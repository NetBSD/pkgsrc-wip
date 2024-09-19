$NetBSD$

--- src/VBox/Additions/common/VBoxService/VBoxService.cpp.orig	2016-03-04 19:23:11.000000000 +0000
+++ src/VBox/Additions/common/VBoxService/VBoxService.cpp
@@ -62,7 +62,7 @@
 #  define pthread_sigmask sigprocmask
 # endif
 #endif
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <pthread.h>
 #endif
 
@@ -1259,4 +1259,3 @@ int main(int argc, char **argv)
 
     return rcExit;
 }
-
