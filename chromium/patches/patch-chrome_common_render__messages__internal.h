$NetBSD: patch-chrome_common_render__messages__internal.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/render_messages_internal.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/render_messages_internal.h
@@ -2139,7 +2139,7 @@ IPC_MESSAGE_CONTROL2(ViewHostMsg_Extensi
                      std::string /* extension_id */,
                      std::string /* name */)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // On OSX, we cannot allocated shared memory from within the sandbox, so
 // this call exists for the renderer to ask the browser to allocate memory
 // on its behalf. We return a file descriptor to the POSIX shared memory.
