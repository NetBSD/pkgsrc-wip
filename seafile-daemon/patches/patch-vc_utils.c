$NetBSD$
Add missing BSD detection, patch adapted from OpenBSDs port

--- daemon/vc-utils.c.orig	2016-10-24 00:54:33.869754994 +0000
+++ daemon/vc-utils.c	2016-10-24 00:55:29.849646175 +0000
@@ -376,7 +376,7 @@
     return hashcmp (sha1, ce_sha1);
 }
 
-#if defined WIN32 || defined __APPLE__
+#if defined WIN32 || defined __APPLE__ || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
 
 /*
  * If the names are different case-sensitively but the same case-insensitively,
