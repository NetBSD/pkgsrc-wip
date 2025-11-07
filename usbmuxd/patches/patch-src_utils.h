$NetBSD$

Fix build with libplist-2.7.0. Already fixed in upstream.

--- src/utils.h.orig	2025-11-07 09:55:55.030114714 +0000
+++ src/utils.h
@@ -78,14 +78,6 @@ char *string_concat(const char *str, ...
 int buffer_read_from_filename(const char *filename, char **buffer, uint64_t *length);
 int buffer_write_to_filename(const char *filename, const char *buffer, uint64_t length);
 
-enum plist_format_t {
-	PLIST_FORMAT_XML,
-	PLIST_FORMAT_BINARY
-};
-
-int plist_read_from_filename(plist_t *plist, const char *filename);
-int plist_write_to_filename(plist_t plist, const char *filename, enum plist_format_t format);
-
 uint64_t mstime64(void);
 void get_tick_count(struct timeval * tv);
 
