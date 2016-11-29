$NetBSD$

--- content/browser/download/base_file.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/download/base_file.cc
@@ -193,7 +193,8 @@ std::unique_ptr<crypto::SecureHash> Base
 }
 
 // OS_WIN, OS_MACOSX and OS_LINUX have specialized implementations.
-#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_LINUX) && \
+    !defined(OS_BSD)
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformation(
     const std::string& client_guid,
     const GURL& source_url,
