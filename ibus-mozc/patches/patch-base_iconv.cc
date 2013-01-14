$NetBSD: patch-base_iconv.cc,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* Fix for BSD iconv, this does not support PREFER_PKGSRC case.

--- base/iconv.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/iconv.cc
@@ -53,7 +53,11 @@ bool IconvHelper(iconv_t ic, const strin
   size_t olen_org = olen;
   iconv(ic, 0, &ilen, 0, &olen);  // reset iconv state
   while (ilen != 0) {
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+    if (iconv(ic, (const char **)(&ibuf), &ilen, &obuf, &olen)
+#else
     if (iconv(ic, reinterpret_cast<char **>(&ibuf), &ilen, &obuf, &olen)
+#endif
         == static_cast<size_t>(-1)) {
       return false;
     }
