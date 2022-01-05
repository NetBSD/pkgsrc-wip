$NetBSD$

Use pkgsrc sqlite3

--- src/zeek-setup.cc.orig	2021-09-22 16:48:15.000000000 +0000
+++ src/zeek-setup.cc
@@ -15,7 +15,7 @@
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 
-#include "zeek/3rdparty/sqlite3.h"
+#include <sqlite3.h>
 
 #define DOCTEST_CONFIG_IMPLEMENT
 #include "zeek/3rdparty/doctest.h"
