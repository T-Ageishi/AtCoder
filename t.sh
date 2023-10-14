#!/bin/bash
#コンパイルとテストの実行
set -e

g++ main.cpp -std=c++17 -I .
oj t -d ./test/