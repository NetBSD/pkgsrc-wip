$NetBSD$

* Import from chromium

--- src/webrtc/src/rtc_base/network.cc.orig	2026-09-29 23:13:58.000000000 +0000
+++ src/webrtc/src/rtc_base/network.cc
@@ -316,7 +316,12 @@ AdapterType GetAdapterTypeFromName(absl:
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
