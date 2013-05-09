$NetBSD: patch-src_navtex_navtex.cxx,v 1.2 2013/05/09 14:40:49 makoto Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/navtex/navtex.cxx.orig	2013-05-03 14:31:34.000000000 +0000
+++ src/navtex/navtex.cxx
@@ -177,12 +177,12 @@ bool read_until_delim( std::istream & is
 	if( ! std::getline( istrm, parsed_str, delim ) ) return false ;
 	std::stringstream sstrm( parsed_str );
 	sstrm >> ref ;
-	return sstrm ;
+	return sstrm.good();
 }
 
 static bool read_until_delim( std::istream & istrm, std::string & ref )
 {
-	return std::getline( istrm, ref, delim );
+	return std::getline( istrm, ref, delim ).good();
 }
 
 class NavtexRecord
