$NetBSD$

--- v8/src/log-utils.h.orig	2016-06-24 01:04:23.000000000 +0000
+++ v8/src/log-utils.h
@@ -9,6 +9,9 @@
 
 #include <cstdarg>
 
+#include <cstdarg>
+#include <cstdio>
+
 #include "src/allocation.h"
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
