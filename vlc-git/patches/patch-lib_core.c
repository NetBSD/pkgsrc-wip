$NetBSD$

--- lib/core.c.orig	2018-03-14 06:17:49.000000000 +0000
+++ lib/core.c
@@ -257,4 +257,4 @@ int64_t libvlc_clock(void)
     return mdate();
 }
 
-const char vlc_module_name[] = "libvlc";
+//const char vlc_module_name[] = "libvlc";
