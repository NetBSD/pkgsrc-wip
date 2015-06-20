$NetBSD: patch-pixz.h,v 1.1 2015/06/20 19:27:52 ishit Exp $

fix "warning: 'archive_read_support_compression_none' is deprecated" from github.

--- pixz.h.orig	2013-01-09 04:25:03.000000000 +0000
+++ pixz.h
@@ -30,6 +30,17 @@
 #endif
 
 
+#pragma mark LIBARCHIVE CHANGES
+
+#include <archive.h>
+#if ARCHIVE_VERSION_NUMBER >= 3000000
+	#define prevent_compression(a) archive_read_support_filter_none(a)
+	#define finish_reading(a) archive_read_free(a)
+#else
+	#define prevent_compression(a) archive_read_support_compression_none(a)
+	#define finish_reading(a) archive_read_finish(a)
+#endif
+
 #pragma mark OPERATIONS
 
 void pixz_list(bool tar);
