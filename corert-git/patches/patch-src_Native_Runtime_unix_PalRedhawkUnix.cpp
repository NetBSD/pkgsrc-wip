$NetBSD$

--- src/Native/Runtime/unix/PalRedhawkUnix.cpp.orig	2016-01-25 00:17:12.000000000 +0000
+++ src/Native/Runtime/unix/PalRedhawkUnix.cpp
@@ -335,7 +335,7 @@ int UTF8ToWideChar(const char* bytes, in
     size_t inbufbytesleft = len;
     size_t outbufbytesleft = bufLen;
 
-    int rc = iconv(cd, &inbuf, &inbufbytesleft, &outbuf, &outbufbytesleft);
+    int rc = iconv(cd, const_cast<const char **>(&inbuf), &inbufbytesleft, &outbuf, &outbufbytesleft);
     if (rc == -1)
     {
         fprintf(stderr, "iconv_open failed with %d\n", errno);
@@ -361,7 +361,7 @@ int WideCharToUTF8(const wchar_t* chars,
     size_t inbufbytesleft = len;
     size_t outbufbytesleft = bufLen;
 
-    int rc = iconv(cd, &inbuf, &inbufbytesleft, &outbuf, &outbufbytesleft);
+    int rc = iconv(cd, const_cast<const char **>(&inbuf), &inbufbytesleft, &outbuf, &outbufbytesleft);
     if (rc == -1)
     {
         fprintf(stderr, "iconv_open failed with %d\n", errno);
