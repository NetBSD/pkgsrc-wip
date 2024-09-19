$NetBSD$

From NetBSD xsrc:

Oct 24 19:37:39 2008 UTC

include string.h and strings.h - for some reason they're missing on sparc64
XXX: need to figure out where the other archs include them so we can get
rid of this

--- include/os.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ include/os.h
@@ -91,6 +91,10 @@ typedef struct _NewClientRec *NewClientP
 
 #include <stdio.h>
 #include <stdarg.h>
+#if defined(__NetBSD__)
+#include <string.h>
+#include <strings.h>
+#endif
 
 #ifdef DDXBEFORERESET
 extern void ddxBeforeReset(void);
