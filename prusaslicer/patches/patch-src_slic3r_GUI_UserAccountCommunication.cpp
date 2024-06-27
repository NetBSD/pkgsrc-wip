$NetBSD$

Treat NetBSD like linux.

Add missing includes.

--- src/slic3r/GUI/UserAccountCommunication.cpp.orig	2024-06-26 15:21:47.000000000 +0000
+++ src/slic3r/GUI/UserAccountCommunication.cpp
@@ -11,6 +11,7 @@
 #include <boost/beast/core/detail/base64.hpp>
 #include <boost/algorithm/string.hpp>
 #include <boost/filesystem.hpp>
+#include <boost/nowide/convert.hpp>
 #include <boost/nowide/cstdio.hpp>
 #include <boost/nowide/fstream.hpp>
 #include <curl/curl.h>
@@ -37,7 +38,7 @@
 #include <CommonCrypto/CommonDigest.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <openssl/evp.h>
 #include <openssl/bio.h>
 #include <openssl/buffer.h>
