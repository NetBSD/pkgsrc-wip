$NetBSD: patch-src_common_encoding.cpp,v 1.1 2015/08/19 20:07:05 yhardy Exp $

ICONV_CONST is defined to be empty by the build system, but the first
parameter of iconv(...) should be const.

--- src/common/encoding.cpp.orig	2015-07-27 08:05:52.000000000 +0000
+++ src/common/encoding.cpp
@@ -112,7 +112,7 @@ private:
 		iconv(ctx, 0, 0, 0, 0);
 
 		// Convert
-		if (iconv(ctx, (ICONV_CONST char **) &data, &inBytes, (char **) &outBuf, &outBytes) == ((size_t) -1)) {
+		if (iconv(ctx, (const char **) &data, &inBytes, (char **) &outBuf, &outBytes) == ((size_t) -1)) {
 			warning("iconv() failed: %s", strerror(errno));
 			delete[] convData;
 
