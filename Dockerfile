FROM alpine

RUN apk add --no-cache -f bash g++ make cmake

RUN wget https://github.com/google/googletest/archive/master.zip
RUN unzip master.zip && \
    mv googletest-master /googletest && \
    mkdir -p /googletest/build && \
    cd /googletest/build && \
    cmake .. && \
    make && \
    make install && \
    cd /

RUN export GTEST_DIR="/googletest/googletest/" GTEST_LIB_DIR="/googletest/build/lib/"

COPY . /tmp/project
WORKDIR /tmp/project

RUN ./build-and-test.sh

ADD entrypoint.sh /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

