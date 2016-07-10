$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/cdefs_aout.h.orig	2016-03-04 19:27:23.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/cdefs_aout.h
@@ -11,7 +11,7 @@
 #define _C_LABEL(x)   __CONCAT(_,x)
 #define _C_LABEL_STRING(x)  "_"x
 
-#define ___RENAME(x)
+//#define ___RENAME(x)
 
 #define __indr_reference(sym,alias) /* nada, since we do weak refs */
 
