$NetBSD: patch-src_zm__utils.cpp,v 1.1 2013/03/24 16:47:47 joerg Exp $

\todo Explain

--- src/zm_utils.cpp.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_utils.cpp
@@ -66,21 +66,6 @@ std::string replaceAll(std::string str, 
   return str;
 }
 
-const std::string stringtf( const char *format, ... )
-{
-  va_list ap;
-  char tempBuffer[8192];
-  std::string tempString;
-
-  va_start(ap, format );
-  vsnprintf( tempBuffer, sizeof(tempBuffer), format , ap );
-  va_end(ap);
-
-  tempString = tempBuffer;
-
-  return( tempString );
-}
-
 const std::string stringtf( const std::string format, ... )
 {
   va_list ap;
