$NetBSD$

Fix build with libplist-2.7.0. Already fixed in upstream.

--- src/utils.c.orig	2025-11-07 10:39:55.456855663 +0000
+++ src/utils.c
@@ -279,51 +279,6 @@ int buffer_write_to_filename(const char 
 	}
 }
 
-int plist_read_from_filename(plist_t *plist, const char *filename)
-{
-	char *buffer = NULL;
-	uint64_t length;
-
-	if (!filename)
-		return 0;
-
-	if (!buffer_read_from_filename(filename, &buffer, &length)) {
-		return 0;
-	}
-
-	if ((length > 8) && (memcmp(buffer, "bplist00", 8) == 0)) {
-		plist_from_bin(buffer, length, plist);
-	} else {
-		plist_from_xml(buffer, length, plist);
-	}
-
-	free(buffer);
-
-	return 1;
-}
-
-int plist_write_to_filename(plist_t plist, const char *filename, enum plist_format_t format)
-{
-	char *buffer = NULL;
-	uint32_t length;
-
-	if (!plist || !filename)
-		return 0;
-
-	if (format == PLIST_FORMAT_XML)
-		plist_to_xml(plist, &buffer, &length);
-	else if (format == PLIST_FORMAT_BINARY)
-		plist_to_bin(plist, &buffer, &length);
-	else
-		return 0;
-
-	int res  = buffer_write_to_filename(filename, buffer, length);
-
-	free(buffer);
-
-	return res;
-}
-
 #ifndef HAVE_CLOCK_GETTIME
 typedef int clockid_t;
 #define CLOCK_MONOTONIC 1
