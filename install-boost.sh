#!/bin/sh

# A simple script to automate downloading and installing boost to the
# current working directory. Will only compile binarys for the libraries
# specified in BOOST_LIBS. However, if this is empty, it will build all
# libraries except MPI (the default setup). This also specifies to only
# build static link libraries (controlled by BOOST_LINKING).
#
# When specifying other libraries to build binaries for, the boost builder
# will automatically include any dependances in other boost libraries.
#
# This will install version 1.49.0.

BOOST_URL="http://sourceforge.net/projects/boost/files/boost/1.49.0/boost_1_49_0.tar.bz2/download"
BOOST_LIBS="--with-filesystem"
BOOST_TOOLSET="gcc"
BOOST_LINKING="static"

wget -O download $BOOST_URL

tar --bzip2 -xf ./download
cd ./boost_1_49_0
./bootstrap.sh
./b2 toolset=$BOOST_TOOLSET link=$BOOST_LINKING $BOOST_LIBS stage
cp -r ./boost ../
cp -r ./stage/lib ../
cd ../
rm -r ./boost_1_49_0
rm download
