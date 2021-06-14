$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.4 2020/04/16 11:51:26 ryoon Exp $

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os/bsd/os_bsd.cpp	2021-06-10 13:28:51.604368642 -0400
@@ -114,6 +114,11 @@
   #include <link_elf.h>
 #endif
 
+#ifdef __NetBSD__
+  #include <lwp.h>
+  #include <link_elf.h>
+#endif
+
 #ifdef __APPLE__
   #include <mach-o/dyld.h>
   // needed by current_stack_region() workaround for Mavericks
@@ -385,7 +390,7 @@
     #ifdef __APPLE__
       #define DEFAULT_LIBPATH "/lib:/usr/lib"
     #elif defined(__NetBSD__)
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+      #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:@PREFIX@/lib:/lib:/usr/lib"
     #else
       #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
     #endif
@@ -2387,7 +2392,7 @@
 #elif defined(__FreeBSD__) || defined(__OpenBSD__)
     pthread_set_name_np(pthread_self(), name);
 #elif defined(__NetBSD__)
-    pthread_setname_np(pthread_self(), "%s", name);
+    pthread_setname_np(pthread_self(), "%s", (char *)(intptr_t)name);
 #endif
   }
 }
