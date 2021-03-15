$NetBSD$

--- src/3rdparty/chromium/content/browser/compositor/viz_process_transport_factory.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/compositor/viz_process_transport_factory.cc
@@ -108,7 +108,7 @@ class HostDisplayClient : public viz::Ho
   HostDisplayClient& operator=(const HostDisplayClient&) = delete;
 
   // viz::HostDisplayClient:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
