$NetBSD$

Needs sys/wait.h for WIFEXITED.

--- modules/fxpackager/src/main/native/library/common/PosixPlatform.cpp.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/fxpackager/src/main/native/library/common/PosixPlatform.cpp
@@ -41,6 +41,7 @@
 #include <assert.h>
 #include <stdbool.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #include <sys/sysctl.h>
 #include <iostream>
@@ -231,9 +232,13 @@ bool PosixProcess::Wait() {
     pid_t wpid;
 
     //TODO Use waitpid instead of wait
+#if defined(__NetBSD__)
+    wpid = wait(&status);
+#else
 #ifdef LINUX
     wait();
 #endif
+#endif
 #ifdef MAC
     wpid = wait(&status);
 #endif
