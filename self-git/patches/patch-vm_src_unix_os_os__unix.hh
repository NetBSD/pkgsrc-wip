$NetBSD$

--- vm/src/unix/os/os_unix.hh.orig	2019-07-21 22:47:42.000000000 +0000
+++ vm/src/unix/os/os_unix.hh
@@ -14,6 +14,8 @@
   || TARGET_OS_VERSION == MACOSX_VERSION \
   || TARGET_OS_VERSION == LINUX_VERSION
      static const int logname_max = 8; 
+# elif TARGET_OS_VERSION == NETBSD_VERSION
+     static const int logname_max = MAXLOGNAME;
 # else
      static const int logname_max = LOGNAME_MAX;
 # endif
@@ -30,4 +32,3 @@
   ||  TARGET_OS_VERSION ==  LINUX_VERSION
     static void setPageAdvisory(char *start, char *end, int code);
 # endif
-
