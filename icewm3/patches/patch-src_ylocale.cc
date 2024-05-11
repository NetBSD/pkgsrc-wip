$NetBSD$

--- src/ylocale.cc.orig	2024-05-11 00:37:57.995111892 +0000
+++ src/ylocale.cc
@@ -204,7 +204,7 @@ char* YLocale::localeString(const wchar_
 
     errno = 0;
     size_t count = iconv(instance->converter->localer(),
-                         &inbuf, &inlen, &outbuf, &outlen);
+                         (char **)&inbuf, &inlen, &outbuf, &outlen);
     if (count == size_t(-1)) {
         static unsigned count, shift;
         if (++count <= 2 || (count - 2) >= (1U << shift)) {
@@ -239,7 +239,7 @@ wchar_t* YLocale::unicodeString(const ch
 
     errno = 0;
     size_t count = iconv(instance->converter->unicode(),
-                         &inbuf, &inlen, &outbuf, &outlen);
+                         (char **)&inbuf, &inlen, &outbuf, &outlen);
     if (count == size_t(-1)) {
         static unsigned count, shift;
         if (++count >= (1U << shift)) {
