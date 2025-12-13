$NetBSD$

* NetBSD hasn't ferror_unlocked()

--- src/basic/fileio.h.orig	2025-12-11 13:03:38.102655025 +0000
+++ src/basic/fileio.h
@@ -3,6 +3,10 @@
 
 #include <stddef.h>
 #include <stdio.h>
+#ifdef __NetBSD__
+#define ferror_unlocked(fp) ferror(fp)
+#endif
+
 
 int read_one_line_file(const char *fn, char **line);
 int read_full_file(const char *fn, char **contents, size_t *size);
