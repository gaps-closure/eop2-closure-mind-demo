ssh-keygen -f $HOME/.ssh/known_hosts -R 172.16.0.2
ssh -X 172.16.0.2 firefox https://localhost:8443

