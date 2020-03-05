#!/bin/bash
export PATH=/usr/lib/mxe/usr/bin:$PATH

MXE_PATH=/usr/lib/mxe

MXE_INCLUDE_PATH=/usr/lib/mxe/usr/i686-w64-mingw32.static/include
MXE_LIB_PATH=/usr/lib/mxe/usr/i686-w64-mingw32.static/lib

MXE_SHARED_INCLUDE_PATH=/usr/lib/mxe/usr/i686-w64-mingw32.shared/include
MXE_SHARED_LIB_PATH=/usr/lib/mxe/usr/i686-w64-mingw32.shared/lib

BOOST_LIB_SUFFIX=-mt \
BOOST_THREAD_LIB_SUFFIX=_win32-mt \
BOOST_INCLUDE_PATH=$MXE_INCLUDE_PATH/boost \
BOOST_LIB_PATH=$MXE_LIB_PATH \
OPENSSL_INCLUDE_PATH=$MXE_INCLUDE_PATH/openssl \
OPENSSL_LIB_PATH=$MXE_LIB_PATH \
BDB_INCLUDE_PATH=$MXE_INCLUDE_PATH \
BDB_LIB_PATH=$MXE_LIB_PATH \
MINIUPNPC_INCLUDE_PATH=$MXE_INCLUDE_PATH \
MINIUPNPC_LIB_PATH=$MXE_LIB_PATH \


cd ./leveldb
TARGET_OS=NATIVE_WINDOWS make CC=i686-w64-mingw32.static-gcc CXX=i686-w64-mingw32.static-g++ libleveldb.a libmemenv.a
cd ..

RANLIB=$MXE_PATH/usr/bin/i686-w64-mingw32.static-ranlib \
      CC=$MXE_PATH/usr/bin/i686-w64-mingw32.static-gcc \
      CXX=$MXE_PATH/usr/bin/i686-w64-mingw32.static-g++ \
      ../dist/configure \
      --disable-replication \
      --enable-mingw \
      --enable-cxx \
      --host x86 \
      --prefix=$MXE_PATH/usr/i686-w64-mingw32.static 

make -j4 -f makefile.linux-mingw