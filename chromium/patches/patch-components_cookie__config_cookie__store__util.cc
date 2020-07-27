$NetBSD$

--- components/cookie_config/cookie_store_util.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/cookie_config/cookie_store_util.cc
@@ -11,7 +11,7 @@
 
 namespace cookie_config {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
