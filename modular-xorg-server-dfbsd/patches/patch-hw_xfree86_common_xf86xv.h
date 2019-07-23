$NetBSD$

--- hw/xfree86/common/xf86xv.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/common/xf86xv.h
@@ -106,7 +106,11 @@ typedef enum {
 
 typedef struct {
     int id;
+#if defined(__NetBSD__)
+    /*const*/ char *name; /* dozens of drivers write to this value */
+#else
     const char *name;
+#endif
     unsigned short width, height;
     XvRationalRec rate;
 } XF86VideoEncodingRec, *XF86VideoEncodingPtr;
