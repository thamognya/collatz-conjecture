FROM ubuntu:latest
RUN mkdir -p /collatzconjecture
WORKDIR /collatzconjecture
RUN apt update && apt upgrade -y && apt install -y gcc
