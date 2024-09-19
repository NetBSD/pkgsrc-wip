$NetBSD$

--- gum/gumprocess.c.orig	2018-03-12 19:53:33.000000000 +0000
+++ gum/gumprocess.c
@@ -45,6 +45,8 @@ gum_process_get_native_os (void)
   return GUM_OS_ANDROID;
 #elif defined (HAVE_QNX)
   return GUM_OS_QNX;
+#elif defined (HAVE_NETBSD)
+  return GUM_OS_NETBSD;
 #else
 # error Unknown OS
 #endif
