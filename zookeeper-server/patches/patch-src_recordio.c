$NetBSD: patch-src_recordio.c,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

SunOS has had htonll since OpenSolaris.
--- src/c/src/recordio.c.orig	2012-02-06 10:48:40.000000000 +0000
+++ src/c/src/recordio.c
@@ -80,6 +80,7 @@ int oa_serialize_int(struct oarchive *oa
     priv->off+=sizeof(i);
     return 0;
 }
+#ifndef __sun
 int64_t htonll(int64_t v)
 {
     int i = 0;
@@ -95,6 +96,7 @@ int64_t htonll(int64_t v)
 
     return v;
 }
+#endif
 
 int oa_serialize_long(struct oarchive *oa, const char *tag, const int64_t *d)
 {
