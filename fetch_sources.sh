#!/bin/bash

# Copyright 2004-present Facebook. All Rights Reserved.

set -e

cd "$(dirname "$0")"

echo "Downloading ICU"
curl -o icu4c.tar.gz https://android.googlesource.com/platform/external/icu/+archive/master/icu4c/source.tar.gz

echo "Extracting ICU"
tar -zxf icu4c.tar.gz -C icu

echo "Downloading JSC"
curl -O http://builds.nightly.webkit.org/files/trunk/src/WebKit-r174650.tar.bz2

echo "Extracting JSC"
tar -jxf WebKit-r174650.tar.bz2 -C jsc --strip 2 WebKit-r174650/Source/JavaScriptCore WebKit-r174650/Source/WTF

