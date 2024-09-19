$NetBSD$

--- include/VBox/ostypes.h.orig	2016-03-04 19:22:57.000000000 +0000
+++ include/VBox/ostypes.h
@@ -157,6 +157,8 @@ typedef enum VBOXOSFAMILY
     VBOXOSFAMILY_Solaris64        = 8,
     VBOXOSFAMILY_MacOSX32         = 9,
     VBOXOSFAMILY_MacOSX64         = 10,
+    VBOXOSFAMILY_NetBSD32         = 11,
+    VBOXOSFAMILY_NetBSD64         = 12,
     /** The usual 32-bit hack. */
     VBOXOSFAMILY_32BIT_HACK = 0x7fffffff
 } VBOXOSFAMILY;
