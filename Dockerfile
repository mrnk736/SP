FROM ubuntu:18.04
COPY ./Main.cpp /home/Main.cpp
COPY ./Bear.h /home/Bear.h
RUN apt-get update
RUN apt-get install nano
