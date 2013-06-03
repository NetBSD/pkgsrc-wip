$NetBSD: patch-src_mongo_platform_random.cpp,v 1.1 2013/06/03 13:58:35 fhajny Exp $

Add NetBSD support.
--- src/mongo/platform/random.cpp.orig	2013-04-22 14:48:39.000000000 +0000
+++ src/mongo/platform/random.cpp	2013-05-30 11:08:13.504585844 +0000
@@ -105,7 +105,7 @@ namespace mongo {
         return new WinSecureRandom();
     }
 
-#elif defined(__linux__) || defined(__sunos__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__sunos__) || defined(__APPLE__) || defined(__netbsd__)
 
     class InputStreamSecureRandom : public SecureRandom {
     public:
