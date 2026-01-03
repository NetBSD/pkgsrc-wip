$NetBSD: patch-channels_rdpdr_client_rdpdr__main.c,v 1.1 2020/05/21 10:11:23 nia Exp $

NetBSD does not have mntent

--- channels/rdpdr/client/rdpdr_main.c.orig	2025-12-05 08:17:55.000000000 +0000
+++ channels/rdpdr/client/rdpdr_main.c
@@ -266,7 +266,7 @@ static UINT rdpdr_send_device_list_remov
 	return rdpdr_send(rdpdr, s);
 }
 
-#if defined(_UWP) || defined(__IOS__)
+#if defined(_UWP) || defined(__IOS__) || defined(__NetBSD__)
 
 static UINT handle_hotplug(WINPR_ATTR_UNUSED RdpdrClientContext* context,
                            WINPR_ATTR_UNUSED RdpdrHotplugEventType type)
@@ -1115,7 +1115,7 @@ out:
 
 #endif
 
-#if !defined(_WIN32) && !defined(__IOS__)
+#if !defined(_WIN32) && !defined(__IOS__) && !defined(__NetBSD__)
 /**
  * Function description
  *
