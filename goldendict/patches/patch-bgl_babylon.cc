$NetBSD$

Set inbuf to const char type because it's a second argument to iconv function,
which on NetBSD has type const char.

--- bgl_babylon.cc	2016-04-26 16:32:50.000000000 +0000
+++ bgl_babylon.cc
@@ -803,7 +803,12 @@ void Babylon::convertToUtf8( std::string
   inbufbytes = s.size();
   outbufbytes = s.size() * 6;
 
+#if defined(__NetBSD__)
+  const char *inbuf;
+#else
   char *inbuf;
+#endif
+
   inbuf = (char *)s.data();
   outbuf = (char*)malloc( outbufbytes + 1 );
   if( !outbuf )
