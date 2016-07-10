$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/EfiCdefs.h.orig	2016-03-04 19:27:23.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/EfiCdefs.h
@@ -262,7 +262,7 @@
   #endif
 #endif /* !(__STDC_VERSION__ >= 199901L) */
 
-#define __RENAME(x)
+//#define __RENAME(x)
 
   /*
   * A barrier to stop the optimizer from moving code or assume live
