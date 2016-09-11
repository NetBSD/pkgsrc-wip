$NetBSD$

Add missing function for NetBSD.

--- libntfs-3g/compat.c.orig	2016-09-11 14:34:51.477253964 +0000
+++ libntfs-3g/compat.c	2016-09-11 14:36:43.021277316 +0000
@@ -248,3 +248,12 @@
  *************************************************************/
 #endif /* HAVE_STRSEP */
 
+#if defined(__NetBSD__)
+#include <fuse.h>
+
+int fuse_version(void)
+{
+    return FUSE_VERSION;
+}
+
+#endif /* __NetBSD__ */
\ No newline at end of file
