$NetBSD$

--- lib/Transforms/Instrumentation/MemorySanitizer.cpp.orig	2017-10-25 17:03:32.656232584 +0000
+++ lib/Transforms/Instrumentation/MemorySanitizer.cpp
@@ -320,6 +320,14 @@ static const MemoryMapParams FreeBSD_X86
   0x380000000000,  // OriginBase
 };
 
+// x86_64 NetBSD
+static const MemoryMapParams NetBSD_X86_64_MemoryMapParams = {
+  0xc00000000000,  // AndMask
+  0x200000000000,  // XorMask
+  0x100000000000,  // ShadowBase
+  0x380000000000,  // OriginBase
+};
+
 static const PlatformMemoryMapParams Linux_X86_MemoryMapParams = {
   &Linux_I386_MemoryMapParams,
   &Linux_X86_64_MemoryMapParams,
@@ -345,6 +353,11 @@ static const PlatformMemoryMapParams Fre
   &FreeBSD_X86_64_MemoryMapParams,
 };
 
+static const PlatformMemoryMapParams NetBSD_X86_MemoryMapParams = {
+  nullptr,
+  &NetBSD_X86_64_MemoryMapParams,
+};
+
 namespace {
 
 /// \brief An instrumentation pass implementing detection of uninitialized
@@ -577,6 +590,15 @@ bool MemorySanitizer::doInitialization(M
           report_fatal_error("unsupported architecture");
       }
       break;
+    case Triple::NetBSD:
+      switch (TargetTriple.getArch()) {
+        case Triple::x86_64:
+          MapParams = NetBSD_X86_MemoryMapParams.bits64;
+          break;
+        default:
+          report_fatal_error("unsupported architecture");
+      }
+      break;
     case Triple::Linux:
       switch (TargetTriple.getArch()) {
         case Triple::x86_64:
