$NetBSD: patch-src_tracker-extract_tracker-extract-gif.c,v 1.1 2014/11/25 13:14:30 thomasklausner Exp $

--- src/tracker-extract/tracker-extract-gif.c.orig	2013-07-11 15:36:07.000000000 +0000
+++ src/tracker-extract/tracker-extract-gif.c
@@ -669,7 +669,7 @@ tracker_extract_get_metadata (TrackerExt
 
 	g_free (uri);
 
-	if (DGifCloseFile (gifFile) != GIF_OK) {
+	if (DGifCloseFile (gifFile, NULL) != GIF_OK) {
 #if GIFLIB_MAJOR < 5
 		PrintGifError ();
 #else  /* GIFLIB_MAJOR < 5 */
