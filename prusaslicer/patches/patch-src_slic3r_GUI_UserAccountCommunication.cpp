$NetBSD$

Treat NetBSD like linux.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2025-03-10 13:20:54.000000000 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -38,7 +38,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
