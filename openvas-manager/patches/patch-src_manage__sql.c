$NetBSD$

Require <libgen.h> for basename(3) on NetBSD.

--- src/manage_sql.c.orig	2016-08-25 12:15:46.000000000 +0000
+++ src/manage_sql.c
@@ -58,6 +58,9 @@
 #include <unistd.h>
 #include <sys/time.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <libgen.h>
+#endif
 
 #include <openvas/base/openvas_string.h>
 #include <openvas/base/openvas_file.h>
