FROM ubuntu:22.04
RUN yes | unminimize
RUN apt-get update && \
    apt-get install -y locales vim tmux less gcc make cmake git sudo build-essential iproute2 iputils-ping netcat-openbsd
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata 
RUN locale-gen ja_JP.UTF-8
ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo
WORKDIR /ubuntu4microps
