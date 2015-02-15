$NetBSD: patch-libpkg_private_pkg.h,v 1.1 2015/02/15 19:06:26 khorben Exp $

--- libpkg/private/pkg.h.orig	2015-02-13 19:35:03.000000000 +0000
+++ libpkg/private/pkg.h
@@ -74,6 +74,8 @@
 #define archive_write_add_filter_none(a) archive_write_set_compression_none(a)
 #define archive_read_support_filter_all(a) archive_read_support_compression_all(a)
 #define archive_read_support_filter_none(a) archive_read_support_compression_none(a)
+#define archive_read_free archive_read_finish
+#define archive_write_free archive_write_finish
 #endif
 
 #define EXTRACT_ARCHIVE_FLAGS  (ARCHIVE_EXTRACT_OWNER |ARCHIVE_EXTRACT_PERM | \
