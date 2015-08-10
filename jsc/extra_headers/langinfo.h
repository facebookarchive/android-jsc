// Copyright 2004-present Facebook. All Rights Reserved.

#ifndef FAKE_LANGINFO_H
#define FAKE_LANGINFO_H 1

// This is a fake implementation of that disables HAVE_LANGINFO_H variable
// soo that DatePrototype.cpp can compile without errors
// langinfo.h is not included by other files in JSC except for DatePrototype.cpp

#undef HAVE_LANGINFO_H

#endif /* langinfo.h  */
