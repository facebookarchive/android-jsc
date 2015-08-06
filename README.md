# JSC build scripts for Android

This repository contains makefile and scripts for building JSC library for Android. Build scripts bundles JSC as a shared library into [android AAR](http://tools.android.com/tech-docs/new-build-system/aar-format) archive, which makes it easy to use it in Android projects build with [Buck](https://buckbuild.com) or [Gradle](https://gradle.org).

## Requirements
 * OS X or Linux - build process have not been tested on other platforms.
 * Android dev environment setup ([SDK](https://developer.android.com/sdk/installing/index.html?pkg=tools) + [NDK](https://developer.android.com/ndk/guides/setup.html))
 * [Buck](https://buckbuild.com) - configured to work with android (see [Quick Start](https://buckbuild.com/setup/quick_start.html) for instructions)
 * [Maven](https://maven.apache.org/download.cgi) (3.2+)
 * Used command line utilities: [ruby](https://www.ruby-lang.org/) (2.0+), zip, curl

## Build instructions

**1. Use the following script to pull in sources for [JSC](https://www.webkit.org) and [ICU](http://site.icu-project.org)**
```bash
./fetch_sources.sh
```

**2. Build AAR with buck (this may take a while)**
```bash
buck build :android-jsc
```
As build step may take a while, consider using `--num-threads` or `--load-limit` options of `buck` command. This may slow the build process down, but should let you use your computer with less hiccups while the build command is running.

**3. Install android AAR in you local maven repository use:**
```bash
./install.sh
```

## Use android-jsc AAR

After installation, android-jsc AAR file should be accessible through maven:

**1. Using BUCK**
```python
remote_file(
  name = 'android-jsc',
  url = 'mvn://org.webkit:android-jsc:r174650',
  sha1 = 'd4b32ee79922794b04bfbbcde0cf9572baaa1b84',
)
```

**2. Using gradle**
```groovy
compile 'org.webkit:android-jsc:r174650'
```

Resulting AAR can be also located in your local maven repository (usually under `~/.m2/repository/org/webkit/android-jsc/`)
