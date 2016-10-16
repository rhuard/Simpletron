FROM ubuntu:14.04

WORKDIR /root

ADD run /root/run

ADD simplebin/add /root/simplebin/add
ADD simplebin/sub /root/simplebin/sub
ADD simplebin/mul /root/simplebin/mul
ADD simplebin/div /root/simplebin/div

ADD simpleass/add /root/simpleass/add
ADD simpleass/sub /root/simpleass/sub
ADD simpleass/mul /root/simpleass/mul
ADD simpleass/div /root/simpleass/div

ENTRYPOINT ["/root/run"]
