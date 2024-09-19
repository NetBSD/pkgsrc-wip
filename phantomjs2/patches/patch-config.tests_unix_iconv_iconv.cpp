$NetBSD: patch-config.tests_unix_iconv_iconv.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Fix for NetBSD iconv(3)

--- src/qt/qtbase/config.tests/unix/iconv/iconv.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/config.tests/unix/iconv/iconv.cpp
@@ -48,7 +48,11 @@ int main(int, char **)
 {
     iconv_t x = iconv_open("", "");
 
+#if defined(__NetBSD__)
+    const char *inp;
+#else
     char *inp;
+#endif
     char *outp;
     size_t inbytes, outbytes;
     iconv(x, &inp, &inbytes, &outp, &outbytes);
