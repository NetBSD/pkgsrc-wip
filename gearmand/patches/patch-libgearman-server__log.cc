--- libgearman-server/log.cc-orig	2013-10-02 14:16:53.000000000 -0400
+++ libgearman-server/log.cc	2013-10-02 14:19:16.000000000 -0400
@@ -54,7 +54,7 @@
 #include <ctime>
 #include <pthread.h>
 
-#ifdef _WIN32
+#if defined(_WIN32) || defined(__NetBSD__)
 # include <malloc.h>
 #else
 # include <alloca.h>
