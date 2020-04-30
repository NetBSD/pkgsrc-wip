$NetBSD$

Use doom_wtohs() for LittleShort() because these macros are used for
importing data from WAD files. Add comments for returned data types.
Rejected by upstream.

--- src/m_swap.h.orig	2014-05-20 04:47:44.000000000 +0000
+++ src/m_swap.h
@@ -126,9 +126,12 @@
 
 #endif
 
-/* CPhipps - Boom's old LONG and SHORT endianness macros are for WAD stuff */
+/* CPhipps - Boom's old LONG and SHORT endianness macros are for WAD stuff
+ *
+ * MB 2020-03-01: Use doom_wtoYT() for all macros
+ */
 
-#define LittleLong(x) doom_wtohl(x)
-#define LittleShort(x) doom_htows(x)
+#define LittleLong(x) doom_wtohl(x)   /* Returns signed 32-bit value */
+#define LittleShort(x) doom_wtohs(x)  /* Returns signed 16-bit value */
 
 #endif
