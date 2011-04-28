$NetBSD: patch-chrome_common_plugin__messages.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/plugin_messages.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/plugin_messages.h
@@ -116,7 +116,7 @@ struct PluginMsg_UpdateGeometry_Param {
   TransportDIB::Handle windowless_buffer;
   TransportDIB::Handle background_buffer;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // This field contains a key that the plug-in process is expected to return
   // to the renderer in its ACK message, unless the value is -1, in which case
   // no ACK message is required.  Other than the special -1 value, the values
