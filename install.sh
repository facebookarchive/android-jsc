#!/bin/bash

# Copyright 2004-present Facebook. All Rights Reserved.

cd "$(dirname "$0")"

AAR_PATH=buck-out/gen/android-jsc.aar

# Make sure that AAR is build, call buck
echo "Building JSC & ICU for Android"
buck build :android-jsc

# Remove gnustl_shared binaries from AAR. This is due to gradle inability to
# handle native libraries with conflicting names coming from multiple
# dependecies. See https://code.google.com/p/android/issues/detail?id=158630
zip -d $AAR_PATH '**/libgnustl_shared.so'

echo "Installing JSC & ICU in local maven repo"
mvn install:install-file -Dfile=$AAR_PATH -DpomFile=android-jsc.pom
