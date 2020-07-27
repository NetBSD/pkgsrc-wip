$NetBSD$

--- third_party/icu/source/common/umapfile.cpp.orig	2020-07-15 19:01:35.000000000 +0000
+++ third_party/icu/source/common/umapfile.cpp
@@ -19,7 +19,7 @@
  *----------------------------------------------------------------------------*/
 /* Defines _XOPEN_SOURCE for access to POSIX functions.
  * Must be before any other #includes. */
-#include "uposixdefs.h"
+//#include "uposixdefs.h"
 
 #include "unicode/putil.h"
 #include "unicode/ustring.h"
