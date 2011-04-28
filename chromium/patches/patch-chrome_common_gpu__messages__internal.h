$NetBSD: patch-chrome_common_gpu__messages__internal.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/gpu_messages_internal.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/gpu_messages_internal.h
@@ -97,7 +97,7 @@ IPC_MESSAGE_CONTROL0(GpuHostMsg_Synchron
 IPC_MESSAGE_CONTROL1(GpuHostMsg_GraphicsInfoCollected,
                      GPUInfo /* GPU logging stats */)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Get the XID for a view ID.
 IPC_SYNC_MESSAGE_CONTROL1_1(GpuHostMsg_GetViewXID,
                             gfx::NativeViewId, /* view */
