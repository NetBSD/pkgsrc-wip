$NetBSD: patch-chrome_gpu_gpu__channel.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/gpu/gpu_channel.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/gpu/gpu_channel.cc
@@ -139,7 +139,7 @@ void GpuChannel::OnCreateViewCommandBuff
   // offscreen rendering and the browser provides whichever platform specific
   // "render target" the GpuCommandBufferStub targets.
   handle = gfx::NativeViewFromId(view_id);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Ask the browser for the view's XID.
   gpu_thread_->Send(new GpuHostMsg_GetViewXID(view_id, &handle));
 #elif defined(OS_MACOSX)
