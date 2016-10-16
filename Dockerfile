FROM ubuntu:14.04

WORKDIR /root

ADD run /root/run

ENTRYPOINT ["/root/run"]
