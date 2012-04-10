$NetBSD: patch-hfaxd_FileSystem.c++,v 1.1 2012/04/10 10:22:45 ftigeot Exp $

--- hfaxd/FileSystem.c++.orig	2010-09-15 14:43:15.000000000 +0000
+++ hfaxd/FileSystem.c++
@@ -728,7 +728,7 @@ HylaFAXServer::nlstUnixFile(FILE* fd, co
 }
 
 static bool
-isTIFF(const TIFFHeader& h)
+isTIFF(const TIFFHeaderClassic& h)
 {
     if (h.tiff_magic != TIFF_BIGENDIAN && h.tiff_magic != TIFF_LITTLEENDIAN)
 	return (false);
@@ -741,7 +741,7 @@ isTIFF(const TIFFHeader& h)
     // byte swap version stamp if opposite byte order
     if ((u.c[0] == 0) ^ (h.tiff_magic == TIFF_BIGENDIAN))
 	TIFFSwabShort(&version);
-    return (version == TIFF_VERSION);
+    return (version == TIFFLIB_VERSION);
 }
 
 bool
@@ -754,7 +754,7 @@ HylaFAXServer::docType(const char* docna
 	if (FileCache::lookup(docname, sb) && S_ISREG(sb.st_mode)) {
 	    union {
 		char buf[512];
-		TIFFHeader h;
+		TIFFHeaderClassic h;
 	    } b;
 	    ssize_t cc = Sys::read(fd, (char*) &b, sizeof (b));
 	    if (cc > 2 && b.buf[0] == '%' && b.buf[1] == '!')
