$NetBSD$

--- test/msan/iconv.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/msan/iconv.cc
@@ -15,8 +15,8 @@ int main(void) {
   char inbuf_[100];
   strcpy(inbuf_, "sample text");
   char outbuf_[100];
-#if defined(__FreeBSD__)
-  // FreeBSD's iconv() expects the 2nd argument be of type 'const char**'.
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+  // FreeBSD/NetBSD's iconv() expects the 2nd argument be of type 'const char**'.
   const char *inbuf = inbuf_;
 #else
   char *inbuf = inbuf_;
