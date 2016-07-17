$NetBSD$

--- content/browser/download/base_file.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/download/base_file.cc
@@ -186,7 +186,8 @@ scoped_ptr<crypto::SecureHash> BaseFile:
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
