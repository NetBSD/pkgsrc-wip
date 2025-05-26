$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/gpu/content_gpu_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/gpu/content_gpu_client.h
@@ -31,6 +31,10 @@ class CONTENT_EXPORT ContentGpuClient {
  public:
   virtual ~ContentGpuClient() {}
 
+  // Allows the embedder to perform platform-specific initialization before
+  // creating the message loop.
+  virtual void PreCreateMessageLoop() {}
+
   // Called during initialization once the GpuService has been initialized.
   virtual void GpuServiceInitialized() {}
 
