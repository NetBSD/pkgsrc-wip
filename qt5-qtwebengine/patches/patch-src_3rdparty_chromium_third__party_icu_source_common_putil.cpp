$NetBSD$

--- src/3rdparty/chromium/third_party/icu/source/common/putil.cpp.orig	2020-07-15 19:01:35.000000000 +0000
+++ src/3rdparty/chromium/third_party/icu/source/common/putil.cpp
@@ -41,7 +41,7 @@
 
 // Defines _XOPEN_SOURCE for access to POSIX functions.
 // Must be before any other #includes.
-#include "uposixdefs.h"
+//#include "uposixdefs.h"
 
 // First, the platform type. Need this for U_PLATFORM.
 #include "unicode/platform.h"
