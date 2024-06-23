$NetBSD$

Treat NetBSD like linux.

Add missing includes.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-06-14 21:54:48.000000000 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -7,6 +7,8 @@
 
 #include <boost/log/trivial.hpp>
 #include <boost/beast/core/detail/base64.hpp>
+#include <boost/algorithm/string/split.hpp>
+#include <boost/nowide/convert.hpp>
 #include <curl/curl.h>
 #include <string>
 
@@ -31,7 +33,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
@@ -567,4 +569,4 @@ std::string CodeChalengeGenerator::sha25
     return std::string(reinterpret_cast<char*>(digest), digestLen);
 }
 #endif // __linux__
-}} // Slic3r::GUI
\ No newline at end of file
+}} // Slic3r::GUI
