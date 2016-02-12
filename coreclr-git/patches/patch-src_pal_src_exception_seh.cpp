$NetBSD$

--- src/pal/src/exception/seh.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/exception/seh.cpp
@@ -29,10 +29,6 @@ Abstract:
 #include "pal/malloc.hpp"
 #include "signal.hpp"
 
-#if HAVE_ALLOCA_H
-#include "alloca.h"
-#endif
-
 #if HAVE_MACH_EXCEPTIONS
 #include "machexception.h"
 #else
