$NetBSD$

Missing include on NetBSD.

--- src/libexpr/primops/fetchGit.cc~	2019-11-01 16:57:52.564146995 +0000
+++ src/libexpr/primops/fetchGit.cc	2019-11-01 16:59:08.187456642 +0000
@@ -6,6 +6,8 @@
 #include "hash.hh"
 
 #include <sys/time.h>
+#include <sys/wait.h>
+
 
 #include <regex>
 
