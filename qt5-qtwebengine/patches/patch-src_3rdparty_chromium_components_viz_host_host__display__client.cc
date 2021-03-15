$NetBSD$

--- src/3rdparty/chromium/components/viz/host/host_display_client.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/viz/host/host_display_client.cc
@@ -56,7 +56,7 @@ void HostDisplayClient::CreateLayeredWin
 }
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
