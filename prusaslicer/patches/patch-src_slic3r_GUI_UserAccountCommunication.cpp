$NetBSD$

Treat NetBSD like linux.

Add missing includes.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-06-21 20:36:12.000000000 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -9,6 +9,7 @@
 #include <boost/log/trivial.hpp>
 #include <boost/beast/core/detail/base64.hpp>
 #include <boost/algorithm/string.hpp>
+#include <boost/nowide/convert.hpp>
 #include <curl/curl.h>
 #include <string>
 
@@ -33,7 +34,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
