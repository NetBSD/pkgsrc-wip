$NetBSD$

Treat NetBSD like linux.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-06-15 08:30:31.450057675 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -31,7 +31,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
@@ -567,4 +567,4 @@ std::string CodeChalengeGenerator::sha25
     return std::string(reinterpret_cast<char*>(digest), digestLen);
 }
 #endif // __linux__
-}} // Slic3r::GUI
\ No newline at end of file
+}} // Slic3r::GUI
