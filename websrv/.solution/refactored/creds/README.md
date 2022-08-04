Generate keys using openssl
```
openssl req  -nodes -new -x509 -days 3650 -keyout server.key -out server.cert
openssl x509 -in server.cert -text | more
```
