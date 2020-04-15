$NetBSD$

iconv prototype was changed to what non-NetBSD has.

--- pan/usenet-utils/mime-utils.cc.orig	2020-04-15 08:49:36.084023027 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -77,11 +77,7 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
-#if defined(__NetBSD__)
-      converted = iconv (cd, &inbuf, &inleft, &outbuf, &outleft);
-#else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
-#endif
 
       if (converted != (size_t) -1 && errno == 0) {
         /*
