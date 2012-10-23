$NetBSD: patch-src_file.cpp,v 1.1 2012/10/23 20:50:14 othyro Exp $

Uses gzFile type instead of void pointer to fix build error.

--- src/file.cpp.orig	2010-09-19 00:05:09.000000000 +0000
+++ src/file.cpp
@@ -310,7 +310,7 @@ FCEUFILE * FCEU_fopen(const char *path, 
 				if(magic==0x088b1f) {
 					 // maybe gzip... 
 
-					void* gzfile = gzopen(fileToOpen.c_str(),"rb");
+					gzFile gzfile = gzopen(fileToOpen.c_str(),"rb");
 					if(gzfile) {
 						delete fp;
 
