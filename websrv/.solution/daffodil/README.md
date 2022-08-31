## Validate the EOP2 Websrv 8 packet data types against DFDL - v0.1

A Data Format Description Language (DFDL) schema describes binary packet 
formats, allowing: 
- Parsing binary packet data into an instance of an information set that is independent of the packet format. 
- Writing (serializing) an information set instance to its native packet format.
The MIND VHDL pipeline is generated from the websrv DFDL, so it is 
important that the on-wire payloads and the DFDL spec match. 

### Run the Script
The 'validate.bash' script validates packet instances stored in hex
format in the p*.txt files:
```
  $ cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/daffodil
  $ ls
      apache-daffodil-3.3.0-bin  p3.txt  p4.txt  p5.txt  p6.txt  p7.txt  p8.txt  
      p9.txt  pa.txt  README.txt  validate.bash
  $ ./validate.bash 
        Parsed p3 rv=0
        Unparsed p3 rv=0
        Files p3.bin and p3.ubin are identical
        Parsed p4 rv=0
        ...
```
Clean up the generated files using:
```
  $ ./validate.bash clean
```
More details are given below:

### PACKET LOG GENERATION (Creation of the p*.txt files)
We run the websrv application (with camera). This can be done using the MIND
ZCU102 board or using the pseudo driver. For the latter, we create four pseudo 
devices:
```
  $ cd ~/gaps/xdcomms-dma/pseudo
  $ sudo ./sue_donimous_unload
  $ sudo ./sue_donimous_load
  $ lsmod | grep sue
```

Next, we run the webserv video processor (orange enclave) and server (green enclave):

```
              Vid-Proc         Web-srv         Web-client
CAMERA  -->  SEND_VIDEO  -->  GET_FRAME  <--  Get_metadata
             ORANGE A53       GREEN  MB         Firefox
```

We start the Vid-Proc and Web-srv, setting the debug-level to 0 using an 
environmental variable: XDCLOGLEVEL=0. For example, we can type the following in two 
separate shell windows.

 Window 1:
```
  $ cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange
  $ LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx0 DMATXDEV=sue_donimous_tx0 XDCLOGLEVEL=0 MYADDR=10.109.23.126 CAMADDR=10.109.23.151 ./websrv  > ~/log_o.txt 2>&1
```

 Window 2:
```
  $ cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green
  $ LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx1 DMATXDEV=sue_donimous_tx1 XDCLOGLEVEL=0  ./websrv  > ~/log_g.txt 2>&1
```

In some cases we may need to turn off verbose printing (setting XDCLOGLEVEL=2),
but uncomment the data_print() function (in send and/or receive functions) of the
in the xdcomms API source code. For example:
```
  $ cd ~/gaps/xdcomms-dma/api
  $ vi xdcomms_dma.c
  $ make clean; make -f Makefile.pseudo
```

### Eight Types of Packet used in the Websrv demo
The table below summarizes the eight types are packet (and CLOSURE assigned tags) used
in the websrv application:

```
Message                 Mux  Sec  Typ  From    To  Comments
------------------------------------------------------------------------
Request_get_frame       1    1     3   Green   Orange  
Response_get_frame      2    2     4   Orange  Green   Large (64028 < 65536 B)
Request_get_metadata    1    1     5   Green   Orange  
Response_get_metadata   2    2     6   Orange  Green   Has Lat/Lon 
Request_run_videoproc   1    1     7   Green   Orange  Start command
Response_run_videoproc  2    2     8   Orange  Green  
Request_send_camcmd     1    1     9   Green   Orange  Camera command 
Response_send_camcmd    2    2    10   Orange  Green  
```

The pragmas below (from the generated RPC code) give the rules for each flow:

```
~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange/orange_rpc.h
~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/green_rpc.h

#pragma cle def TAG_REQUEST_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,3]}}]}

#pragma cle def TAG_RESPONSE_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,4]}}]}

#pragma cle def TAG_REQUEST_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,5]}}]}

#pragma cle def TAG_RESPONSE_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,6]}}]}

#pragma cle def TAG_REQUEST_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,7]}}]}

#pragma cle def TAG_RESPONSE_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,8]}}]}

#pragma cle def TAG_REQUEST_SEND_CAMCMD {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,9]}}]}

#pragma cle def TAG_RESPONSE_SEND_CAMCMD {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,10]}}]}
```

Orange packets logs:
```
RX_PKT (len=28) 00010103 001459B1 00000000 80000006 00000000 00000000 00000000
TX_PKT (len=64028) 00020204 FA146CCD 00000000 00000000 00000000 00000000 00000000 ....
RX_PKT (len=28) 00010105 00148F68 17C41440 00000005 17A7590F 0000557E D06E17A7
TX_PKT (len=60) 00020206 0034790F 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000014 00000000 00000000 00000000
RX_PKT (len=28) 00010107 00143AD0 00000000 00000001 00000000 00000000 00000000
TX_PKT (len=28) 00020208 00144816 00000000 00000000 00000000 00000000 00000000
RX_PKT (len=50) 00010109 002AF236 00000000 00000000 00000000 00000000 00000000 00000000 00008000 0001BAC0 00007FFD 4BB30000 0000
TX_PKT (len=28) 0002020A 0014FDAE 00000000 00000000 00000000 00000000 00000000
```

### VALIDATION Script High-level Description
The 'validate.bash' script script takes as input the saved (hex formatted) packets,
then runs the following:
```
  $ xxd -r -p hex bin                       # Converts packet logs file (hex) to binary
  $ daffodil parse   -s <DFDL-SPEC> -o test.infoset <INPUT-BIN>
  $ daffodil unparse -s <DFDL-SPEC> -o test.bin test.infoset
  $ diff -s test.bin <INPUT-BIN>            # parse . unparse =? id
```
We can also inspect the infoset output (*.infoset): 

For the EOP CLOSURE Phase 2 (websrv) demo, the DFDL schema the script uses is in:
```
    ../partitioned/multithreaded/autogen/websrv_bw.dfdl
```

The validation uses the 'daffodil' command (stored in the 'apache-daffodil-3.3.0-bin'
directory) copied from: 
```
    https://daffodil.apache.org/
    wget https://www.apache.org/dyn/closer.lua/daffodil/3.3.0/bin/apache-daffodil-3.3.0-bin.zip
```



