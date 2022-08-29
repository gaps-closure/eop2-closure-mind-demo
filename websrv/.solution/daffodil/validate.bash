#!/bin/bash
DAF='./apache-daffodil-3.3.0-bin/bin/daffodil'
SCH='../partitioned/multithreaded/autogen/websrv_bw.dfdl'

function val () {
  for f in p*.txt
  do
    s=${f::-4}
    xxd -r -p $f $s.bin
    $DAF parse -s $SCH -o $s.infoset $s.bin
    RV=$?
    if [ $RV -ne 0 ]; then
      echo $f "failed to parse rv="$RV
      exit
    fi
    echo "Parsed" $s "rv="$?
    $DAF unparse -s $SCH -o $s.ubin $s.infoset
    RV=$?
    if [ $RV -ne 0 ]; then
      echo $f "failed to unparse rv="$RV
      exit
    fi
    echo "Unparsed" $s "rv="$?
    diff -s $s.bin $s.ubin
  done
}

if [ "$1" == "clean" ]; then
  rm -f p*.bin p*.ubin p*.infoset
else
  val
fi

