$NetBSD: patch-src_zm__utils.h,v 1.2 2015/04/05 08:51:08 dsainty Exp $

\todo Explain

--- src/zm_utils.h.orig	2018-12-08 14:22:36.000000000 +0000
+++ src/zm_utils.h
@@ -33,7 +33,6 @@ std::string trimSet(std::string str, std
 std::string replaceAll(std::string str, std::string from, std::string to);
 
 const std::string stringtf( const char *format, ... );
-const std::string stringtf( const std::string &format, ... );
 
 bool startsWith( const std::string &haystack, const std::string &needle );
 StringVector split( const std::string &string, const std::string &chars, int limit=0 );
