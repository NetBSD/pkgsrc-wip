$NetBSD$

Add support for NetBSD.

--- src/hashcat.c.orig	2016-08-19 09:45:29.000000000 +0000
+++ src/hashcat.c
@@ -14,6 +14,10 @@
 #include <stdio.h>
 #endif
 
+#ifdef __NetBSD__
+#include <stdio.h>
+#endif
+
 #include <common.h>
 #include <shared.h>
 #include <rp_kernel_on_cpu.h>
@@ -6607,7 +6611,7 @@ int main (int argc, char **argv)
   char *exec_path = get_exec_path ();
 
 
-  #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+  #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
   char *resolved_install_folder = realpath (INSTALL_FOLDER, NULL);
   char *resolved_exec_path      = realpath (exec_path, NULL);
