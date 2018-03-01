$NetBSD$

Set inBuf to const char type because it's a second argument to iconv function,
which on NetBSD has type const char.

--- mdictparser.cc	2016-04-26 16:32:50.000000000 +0000
+++ mdictparser.cc
@@ -187,7 +187,11 @@ QString MdictParser::toUtf16( const char
   vector<char> result;
   const static int CHUNK_SIZE = 512;
   char buf[CHUNK_SIZE];
+#if defined(__NetBSD__)
+  const char ** inBuf = (const char ** )&from;
+#else
   char ** inBuf = ( char ** )&from;
+#endif
 
   while ( fromSize )
   {
