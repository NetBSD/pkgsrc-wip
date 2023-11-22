$NetBSD$

NetBSD fixes.

--- folly/Subprocess.cpp.orig	2023-11-19 20:05:55.000000000 +0000
+++ folly/Subprocess.cpp
@@ -49,6 +49,10 @@
 #include <folly/system/AtFork.h>
 #include <folly/system/Shell.h>
 
+#ifdef __NetBSD__
+extern char **environ;
+#endif
+
 constexpr int kExecFailure = 127;
 constexpr int kChildFailure = 126;
 
@@ -685,7 +689,7 @@ int Subprocess::prepareChild(
 #endif
 
   if (options.processGroupLeader_) {
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     if (setpgrp() == -1) {
 #else
     if (setpgrp(getpid(), getpgrp()) == -1) {
