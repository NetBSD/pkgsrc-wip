$NetBSD: patch-include_recordio.h,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

SunOS has htonll since OpenSolaris.
--- src/c/include/recordio.h.orig	2012-02-06 10:48:40.000000000 +0000
+++ src/c/include/recordio.h
@@ -73,7 +73,10 @@ void close_buffer_iarchive(struct iarchi
 char *get_buffer(struct oarchive *);
 int get_buffer_len(struct oarchive *);
 
+#ifndef __sun
+/* Solaris already implements htonll */
 int64_t htonll(int64_t v);
+#endif
 
 #ifdef __cplusplus
 }
