$NetBSD$

Reason unknown (patch ported from version 6.03.2).

--- include/interlocks.h.orig	2019-07-12 21:54:19.000000000 +0000
+++ include/interlocks.h
@@ -37,7 +37,8 @@
 //Channels
 #define _CR (0x0020)
 #define _CW (0x0040)
-#define _CB (0x0060)
+//#define _CB (0x0060)
+#define CSOUND_CB (0x0060)
 
 //Stack
 #define SK (0x0080)
