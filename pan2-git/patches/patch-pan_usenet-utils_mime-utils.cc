$NetBSD: patch-pan_usenet-utils_mime-utils.cc,v 1.1 2012/10/28 21:05:48 rhialto Exp $

Fix build with NetBSD's iconv().

--- pan/usenet-utils/mime-utils.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -77,7 +77,11 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
+#if defined(__NetBSD__)
+      converted = iconv (cd, &inbuf, &inleft, &outbuf, &outleft);
+#else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
+#endif
 
       if (converted != (size_t) -1 && errno == 0) {
         /*
