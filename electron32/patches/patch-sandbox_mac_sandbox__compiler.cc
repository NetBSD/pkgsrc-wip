$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/sandbox_compiler.cc.orig	2024-10-18 12:34:31.993766300 +0000
+++ sandbox/mac/sandbox_compiler.cc
@@ -47,6 +47,7 @@ bool SandboxCompiler::SetParameter(const
 }
 
 bool SandboxCompiler::CompileAndApplyProfile(std::string& error) {
+#if !IS_MAS_BUILD()
   if (mode_ == Target::kSource) {
     std::vector<const char*> params;
 
@@ -67,6 +68,9 @@ bool SandboxCompiler::CompileAndApplyPro
     }
   }
   return false;
+#else
+  return true;
+#endif
 }
 
 bool SandboxCompiler::CompilePolicyToProto(mac::SandboxPolicy& policy,
