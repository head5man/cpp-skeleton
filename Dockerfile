FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install build-essential -y
RUN apt-get install cmake -y
RUN apt-get install git -y

LABEL org.opencontainers.image.title="Ubuntu cmake build" \
      org.opencontainers.image.description="Build cmake based application" \
      org.opencontainers.image.authors="@justtuomas"

# Create directory in container image for app code
RUN mkdir -p /usr/src/app/build

# Copy app code (..) to /usr/src/app in container image
COPY . /usr/src/app

# Set working directory context
WORKDIR /usr/src/app/build

RUN cmake ..

RUN cmake --build .
