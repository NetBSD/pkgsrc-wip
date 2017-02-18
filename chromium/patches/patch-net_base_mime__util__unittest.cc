$NetBSD$

--- net/base/mime_util_unittest.cc.orig	2017-02-02 02:02:56.000000000 +0000
+++ net/base/mime_util_unittest.cc
@@ -243,7 +243,7 @@ TEST(MimeUtilTest, TestGetExtensionsForM
     { "MeSsAge/*",  1, "eml" },
     { "image/bmp",  1, "bmp" },
     { "video/*",    6, "mp4" },
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_IOS)
+#if (defined(OS_POSIX) && !defined(OS_MACOSX)) || defined(OS_IOS)
     { "video/*",    6, "mpg" },
 #else
     { "video/*",    6, "mpeg" },
