$NetBSD$

--- gum/backend-posix/gummemory-posix.c.orig	2018-03-12 19:53:33.000000000 +0000
+++ gum/backend-posix/gummemory-posix.c
@@ -12,7 +12,7 @@
 #include <unistd.h>
 #include <sys/mman.h>
 
-#if defined (HAVE_LINUX)
+#if defined (HAVE_LINUX) || defined (HAVE_NETBSD)
 # define GUM_MAP_LAZY MAP_NORESERVE
 #elif defined (HAVE_QNX)
 # define GUM_MAP_LAZY MAP_LAZY
@@ -303,4 +303,3 @@ _gum_page_protection_to_posix (GumPagePr
 
   return posix_page_prot;
 }
-
