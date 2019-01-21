#!/bin/bash

qmake "RELEASE=1" xfuel.pro

make -j4 -f Makefile