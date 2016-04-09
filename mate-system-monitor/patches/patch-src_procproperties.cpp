$NetBSD$

Fix Darwin build.

--- src/procproperties.cpp.orig	2015-09-25 11:36:19.000000000 +0000
+++ src/procproperties.cpp
@@ -26,7 +26,7 @@
 #include <glibtop/procstate.h>
 #if defined (__linux__)
 #include <asm/param.h>
-#elif defined (__NetBSD__) || defined (__OpenBSD__)
+#elif defined (__NetBSD__) || defined (__OpenBSD__) || defined (__APPLE__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -114,7 +114,7 @@ fill_proc_properties (GtkWidget *tree, P
 
     get_process_memory_info(info);
 
-#if defined (__NetBSD__) || defined (__OpenBSD__)
+#if defined (__NetBSD__) || defined (__OpenBSD__) || defined(__APPLE__)
     struct clockinfo cinf;
     size_t size = sizeof (cinf);
     int HZ;
