FROM ubuntu:14.04

WORKDIR /root

ADD run /root/run
ADD simplebin/add /root/simplebin/add
ADD simplebin/sub /root/simplebin/sub
ADD simplebin/mul /root/simplebin/mul
ADD simplebin/div /root/simplebin/div

ENTRYPOINT ["/root/run"]
