#!/bin/bash
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
#   Build JNI interface for Android
#   Targets Android API level 8, ARM architecture (see below)
#
#   Requires these environment variables be set, e.g.:
#
#     ANDROID_NDK_ROOT=$HOME/android-ndk-r10e
#     TOOLCHAIN_NAME=arm-linux-androideabi-4.9
#     TOOLCHAIN_VERSION=4.9
#     TOOLCHAIN_HOST=arm-linux-androideabi
#     TOOLCHAIN_ARCH=arm
#     TOOLCHAIN_PATH=$ANDROID_NDK_ROOT/toolchains/$TOOLCHAIN_NAME/prebuilt/linux-x86_64/bin
#
#   Exit if any step fails
set -e

export ANDROID_API_LEVEL=android-8
export ANDROID_SYS_ROOT=$ANDROID_NDK_ROOT/platforms/$ANDROID_API_LEVEL/arch-$TOOLCHAIN_ARCH
if [ "$1" = "-d" ]; then
    MAKE_OPTIONS=VERBOSE=1
fi

source ../../../builds/android/android_build_helper.sh
android_build_env

#   Build any dependent libraries
( cd ../../../../czmq/bindings/jni/android; ./build.sh )

#   Ensure we've built dependencies for Android
echo "********  Building zebra Android native libraries"
( cd ../../../builds/android && ./build.sh )

#   Ensure we've built JNI interface
echo "********  Building zebra JNI interface & classes"
( cd .. && gradle build jar )

rm -rf build && mkdir build && cd build
cmake -v -DCMAKE_TOOLCHAIN_FILE=../android_toolchain.cmake ..

#   CMake wrongly searches current directory and then toolchain path instead
#   of lib path for these files, so make them available temporarily
ln -s $ANDROID_SYS_ROOT/usr/lib/crtend_so.o
ln -s $ANDROID_SYS_ROOT/usr/lib/crtbegin_so.o

echo "********  Building zebra JNI for Android"
make $MAKE_OPTIONS

echo "********  Building zebra.jar for Android"
#   Copy class files into org/zeromq/etc.
unzip -q ../../build/libs/zebra*.jar
unzip -q -o ../../../../../czmq/bindings/jni/android/czmq-android.jar

#   Copy native libraries into lib/armeabi
mkdir -p lib/armeabi
mv libzebrajni.so lib/armeabi
cp ../../../../builds/android/prefix/*/lib/*.so lib/armeabi

cp $ANDROID_NDK_ROOT/sources/cxx-stl/gnu-libstdc++/$TOOLCHAIN_VERSION/libs/armeabi/libgnustl_shared.so lib/armeabi

zip -r -m ../zebra-android.jar lib/ org/ META-INF/
cd ..
rm -rf build

echo "********  Complete"
