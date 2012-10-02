$NetBSD: patch-db__nonce.cpp,v 1.2 2012/10/02 08:48:46 fhajny Exp $

Add support for NetBSD.
--- src/mongo/db/nonce.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/nonce.cpp
@@ -38,7 +38,7 @@ namespace mongo {
         if( _initialized ) return;
         _initialized = true;
 
-#if defined(__linux__) || defined(__sunos__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__sunos__) || defined(__APPLE__) || defined(__netbsd__)
         _devrandom = new ifstream("/dev/urandom", ios::binary|ios::in);
         if ( !_devrandom->is_open() )
             massert( 10353 , std::string("can't open dev/urandom: ") + strerror(errno), 0 );
