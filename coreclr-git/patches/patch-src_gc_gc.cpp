$NetBSD$

--- src/gc/gc.cpp.orig	2016-02-04 01:25:17.000000000 +0000
+++ src/gc/gc.cpp
@@ -20,6 +20,8 @@
 
 #include "gcpriv.h"
 
+#include <time.h>
+
 #define USE_INTROSORT
 
 #if defined(GC_PROFILING) || defined(FEATURE_EVENT_TRACE)
