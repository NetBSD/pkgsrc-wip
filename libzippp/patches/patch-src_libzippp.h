$NetBSD$

Fix handling of error format
From upstream:
https://github.com/ctabin/libzippp/commit/22df3bb79597b0a9587a31143bf05006bca9c70d

--- src/libzippp.h.orig	2022-05-23 21:32:28.000000000 +0000
+++ src/libzippp.h
@@ -51,7 +51,7 @@ struct zip_source;
 #define LIBZIPPP_DEFAULT_PROGRESSION_PRECISION 0.5
 
 // allow custom debug handling when errors occurs in libzippp
-#define LIBZIPPP_ERROR_DEBUG(str, errormsg) fprintf(stderr, str "\n", errormsg);
+#define LIBZIPPP_ERROR_DEBUG(str, errormsg) fprintf(stderr, (str"\n"), (errormsg));
 
 //libzip documentation
 //- http://www.nih.at/libzip/libzip.html
