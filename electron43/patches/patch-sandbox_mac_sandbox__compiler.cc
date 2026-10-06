$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/sandbox_compiler.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/mac/sandbox_compiler.cc
@@ -7,6 +7,7 @@
 #include <string>
 #include <vector>
 
+#include "electron/mas.h"
 #include "sandbox/mac/seatbelt.h"
 
 namespace sandbox {
@@ -47,6 +48,7 @@ bool SandboxCompiler::SetParameter(const
 }
 
 bool SandboxCompiler::CompileAndApplyProfile(std::string& error) {
+#if !IS_MAS_BUILD()
   if (mode_ == Target::kSource) {
     std::vector<const char*> params;
 
@@ -67,6 +69,9 @@ bool SandboxCompiler::CompileAndApplyPro
     }
   }
   return false;
+#else
+  return true;
+#endif
 }
 
 bool SandboxCompiler::CompilePolicyToProto(mac::SandboxPolicy& policy,
