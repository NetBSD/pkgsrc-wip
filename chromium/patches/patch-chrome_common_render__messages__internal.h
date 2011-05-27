$NetBSD: patch-chrome_common_render__messages__internal.h,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/common/render_messages_internal.h.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/common/render_messages_internal.h
@@ -1931,7 +1931,7 @@ IPC_MESSAGE_ROUTED3(ViewHostMsg_CommandS
                     bool /* is_enabled */,
                     int /* checked_state */)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // On OSX, we cannot allocated shared memory from within the sandbox, so
 // this call exists for the renderer to ask the browser to allocate memory
 // on its behalf. We return a file descriptor to the POSIX shared memory.
