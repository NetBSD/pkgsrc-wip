$NetBSD: patch-run.c,v 1.1 2011/05/28 15:54:14 cheusov Exp $

--- run.c.orig	2011-04-18 15:23:28.000000000 +0000
+++ run.c
@@ -40,6 +40,14 @@ THIS SOFTWARE.
 #include "awk.h"
 #include "awkgram.h"
 
+#ifndef HAVE_FUNC1_FPURGE
+int fpurge (FILE *stream);
+#endif
+
+#ifndef HAVE_FUNC3_STRLCAT
+size_t strlcat(char *dst, const char *src, size_t size);
+#endif
+
 #define tempfree(x)	do { if (istemp(x)) tfree(x); } while (/*CONSTCOND*/0)
 
 void stdinit(void);
