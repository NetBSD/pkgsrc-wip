$NetBSD$

--- base/process/internal_linux.h.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/internal_linux.h
@@ -14,6 +14,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
