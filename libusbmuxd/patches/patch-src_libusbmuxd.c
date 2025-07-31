$NetBSD$

Add NetBSD support.

--- src/libusbmuxd.c.orig	2025-07-31 18:22:11.292175556 +0000
+++ src/libusbmuxd.c
@@ -658,7 +658,7 @@ static void get_bundle_id()
 
 static void get_prog_name()
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined (__NetBSD__)
 	const char *pname = getprogname();
 	if (pname) {
 		prog_name = strdup(pname);
