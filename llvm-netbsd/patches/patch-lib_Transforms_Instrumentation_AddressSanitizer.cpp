$NetBSD$

--- lib/Transforms/Instrumentation/AddressSanitizer.cpp.orig	2018-05-11 01:06:43.059844428 +0000
+++ lib/Transforms/Instrumentation/AddressSanitizer.cpp
@@ -109,6 +109,7 @@ static const uint64_t kFreeBSD_ShadowOff
 static const uint64_t kFreeBSD_ShadowOffset64 = 1ULL << 46;
 static const uint64_t kNetBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kNetBSD_ShadowOffset64 = 1ULL << 46;
+static const uint64_t kNetBSDKasan_ShadowOffset64 = 0xdffffc0000000000;
 static const uint64_t kPS4CPU_ShadowOffset64 = 1ULL << 40;
 static const uint64_t kWindowsShadowOffset32 = 3ULL << 28;
 
@@ -529,9 +530,12 @@ static ShadowMapping getShadowMapping(Tr
       Mapping.Offset = kSystemZ_ShadowOffset64;
     else if (IsFreeBSD)
       Mapping.Offset = kFreeBSD_ShadowOffset64;
-    else if (IsNetBSD)
-      Mapping.Offset = kNetBSD_ShadowOffset64;
-    else if (IsPS4CPU)
+    else if (IsNetBSD && IsX86_64) {
+      if (IsKasan)
+        Mapping.Offset = kNetBSDKasan_ShadowOffset64;
+      else
+        Mapping.Offset = kNetBSD_ShadowOffset64;
+    } else if (IsPS4CPU)
       Mapping.Offset = kPS4CPU_ShadowOffset64;
     else if (IsLinux && IsX86_64) {
       if (IsKasan)
