// Copyright 2004-present Facebook. All Rights Reserved.

#ifndef COLLACTION_HACK_H
#define COLLACTION_HACK_H 1

// This extra header file allow CollatorDefault.cpp to compile with
// UCONFIG_NO_COLLATION flag enabled. We need to enable that flag because
// otherwise we'd need to include ICU library in our builds.
// It turns out that since no-one is using this flag to test WebKit builds
// the CollatorDefault.cpp won't compile because of the following issues:
// 1) Definition of StringView is missing
// 2) methods of Collator class it defines are declared static in a header file,
//    therefore the "const" modifier for those methods is illegal
//
// This file will be included with -include preprocessor option for compiling
// ColloratorDefault.cpp, thus we can apply some hacks here to workaround the
// issues mentioned above:
// 1) We include StringView.h header
// 2) We redefine "const" to empty string. The issue here is that because of
//    that "const char*" will be renamed to "char*". Therefore we also define
//    "char" to be replaced by "ConstChar" type that is a typedef of a
//    "const char*" but it's typedef definition comes before #define statement
//    for "const". Moreover to avoid #define statement to apply for the header
//    files that CollatorDefault.cpp is including we first include all the files
//    that are required there, so that when the #include statement is hit in
//    ColloratorDefault.cpp those are already included and preprocessor won't
//    process them again and won't replace "const" tokens they may contain

#include "WTF/config.h"
#include <wtf/unicode/Collator.h>
#include <wtf/text/StringView.h>

typedef const char ConstChar;
#define const
#define char ConstChar

#endif /* COLLACTION_HACK_H */
