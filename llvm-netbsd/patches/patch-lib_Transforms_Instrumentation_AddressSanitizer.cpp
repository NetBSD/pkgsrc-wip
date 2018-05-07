$NetBSD$

--- lib/Transforms/Instrumentation/AddressSanitizer.cpp.orig	2018-02-16 03:29:35.000000000 +0000
+++ lib/Transforms/Instrumentation/AddressSanitizer.cpp
@@ -107,7 +107,9 @@ static const uint64_t kMIPS64_ShadowOffs
 static const uint64_t kAArch64_ShadowOffset64 = 1ULL << 36;
 static const uint64_t kFreeBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kFreeBSD_ShadowOffset64 = 1ULL << 46;
+static const uint64_t kNetBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kNetBSD_ShadowOffset64 = 1ULL << 46;
+static const uint64_t kNetBSDKasan_ShadowOffset64 = 0xdffffc0000000000;
 static const uint64_t kPS4CPU_ShadowOffset64 = 1ULL << 40;
 static const uint64_t kWindowsShadowOffset32 = 3ULL << 28;
 
@@ -508,6 +510,8 @@ static ShadowMapping getShadowMapping(Tr
       Mapping.Offset = kMIPS32_ShadowOffset32;
     else if (IsFreeBSD)
       Mapping.Offset = kFreeBSD_ShadowOffset32;
+    else if (IsNetBSD)
+      Mapping.Offset = kNetBSD_ShadowOffset32;
     else if (IsIOS)
       // If we're targeting iOS and x86, the binary is built for iOS simulator.
       Mapping.Offset = IsX86 ? kIOSSimShadowOffset32 : kIOSShadowOffset32;
@@ -526,9 +530,12 @@ static ShadowMapping getShadowMapping(Tr
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
