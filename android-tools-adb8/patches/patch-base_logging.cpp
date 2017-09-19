$NetBSD$

--- base/logging.cpp.orig	2017-06-27 22:39:52.000000000 +0000
+++ base/logging.cpp
@@ -35,6 +35,7 @@
 #include <sys/uio.h>
 #endif
 
+#include <cstring>
 #include <iostream>
 #include <limits>
 #include <mutex>
