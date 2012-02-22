$NetBSD: patch-db__nonce.cpp,v 1.1 2012/02/22 11:36:27 bartoszkuzma Exp $

Add NetBSD support

--- db/nonce.cpp.orig	2011-12-14 17:18:48.000000000 +0000
+++ db/nonce.cpp
@@ -37,7 +37,7 @@ namespace mongo {
         if( _initialized ) return;
         _initialized = true;
 
-#if defined(__linux__) || defined(__sunos__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__sunos__) || defined(__APPLE__) || defined(__netbsd__)
         _devrandom = new ifstream("/dev/urandom", ios::binary|ios::in);
         massert( 10353 ,  "can't open dev/urandom", _devrandom->is_open() );
 #elif defined(_WIN32)
