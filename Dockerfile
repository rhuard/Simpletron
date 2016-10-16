FROM ubuntu:14.04

WORKDIR /root

ADD run /root/run
ADD simplebin/add /root/simplebin/add

ENTRYPOINT ["/root/run"]
