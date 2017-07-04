$NetBSD$

--- lib/Transforms/Instrumentation/AddressSanitizer.cpp.orig	2017-07-04 15:51:35.232369546 +0000
+++ lib/Transforms/Instrumentation/AddressSanitizer.cpp
@@ -80,6 +80,7 @@ static const uint64_t kMIPS64_ShadowOffs
 static const uint64_t kAArch64_ShadowOffset64 = 1ULL << 36;
 static const uint64_t kFreeBSD_ShadowOffset32 = 1ULL << 30;
 static const uint64_t kFreeBSD_ShadowOffset64 = 1ULL << 46;
+static const uint64_t kNetBSD_ShadowOffset64 = 1ULL << 46;
 static const uint64_t kPS4CPU_ShadowOffset64 = 1ULL << 40;
 static const uint64_t kWindowsShadowOffset32 = 3ULL << 28;
 // The shadow memory space is dynamically allocated.
@@ -394,6 +395,7 @@ static ShadowMapping getShadowMapping(Tr
   bool IsAndroid = TargetTriple.isAndroid();
   bool IsIOS = TargetTriple.isiOS() || TargetTriple.isWatchOS();
   bool IsFreeBSD = TargetTriple.isOSFreeBSD();
+  bool IsNetBSD = TargetTriple.isOSNetBSD();
   bool IsPS4CPU = TargetTriple.isPS4CPU();
   bool IsLinux = TargetTriple.isOSLinux();
   bool IsPPC64 = TargetTriple.getArch() == llvm::Triple::ppc64 ||
@@ -438,6 +440,8 @@ static ShadowMapping getShadowMapping(Tr
       Mapping.Offset = kSystemZ_ShadowOffset64;
     else if (IsFreeBSD)
       Mapping.Offset = kFreeBSD_ShadowOffset64;
+    else if (IsNetBSD)
+      Mapping.Offset = kNetBSD_ShadowOffset64;
     else if (IsPS4CPU)
       Mapping.Offset = kPS4CPU_ShadowOffset64;
     else if (IsLinux && IsX86_64) {
