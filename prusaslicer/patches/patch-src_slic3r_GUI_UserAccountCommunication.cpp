$NetBSD$

Treat NetBSD like linux.

Add missing includes.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-06-21 20:36:12.000000000 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -33,7 +33,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
