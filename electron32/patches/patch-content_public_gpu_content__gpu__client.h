$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/gpu/content_gpu_client.h.orig	2024-10-18 12:34:14.470355000 +0000
+++ content/public/gpu/content_gpu_client.h
@@ -30,6 +30,10 @@ class CONTENT_EXPORT ContentGpuClient {
  public:
   virtual ~ContentGpuClient() {}
 
+  // Allows the embedder to perform platform-specific initialization before
+  // creating the message loop.
+  virtual void PreCreateMessageLoop() {}
+
   // Called during initialization once the GpuService has been initialized.
   virtual void GpuServiceInitialized() {}
 
