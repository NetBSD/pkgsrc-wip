$NetBSD$

--- source/Core/ArchSpec.cpp.orig	2017-04-07 18:27:43.313975678 +0000
+++ source/Core/ArchSpec.cpp
@@ -989,29 +989,34 @@ bool ArchSpec::SetTriple(llvm::StringRef
 }
 
 void ArchSpec::MergeFrom(const ArchSpec &other) {
-  if (TripleVendorIsUnspecifiedUnknown() &&
-      !other.TripleVendorIsUnspecifiedUnknown())
-    GetTriple().setVendor(other.GetTriple().getVendor());
-  if (TripleOSIsUnspecifiedUnknown() && !other.TripleOSIsUnspecifiedUnknown())
-    GetTriple().setOS(other.GetTriple().getOS());
-  if (GetTriple().getArch() == llvm::Triple::UnknownArch)
-    GetTriple().setArch(other.GetTriple().getArch());
-  if (GetTriple().getEnvironment() == llvm::Triple::UnknownEnvironment &&
-      !TripleVendorWasSpecified()) {
-    if (other.TripleVendorWasSpecified())
-      GetTriple().setEnvironment(other.GetTriple().getEnvironment());
-  }
   // If this and other are both arm ArchSpecs and this ArchSpec is a generic
-  // "some kind of arm"
-  // spec but the other ArchSpec is a specific arm core, adopt the specific arm
-  // core.
+  // "some kind of arm" spec but the other ArchSpec is a specific arm core, adopt
+  // the specific arm core.
+  bool ShouldOverrideCore = false;
+
+  if (GetCore() == ArchSpec::kCore_invalid && other.GetCore() != ArchSpec::kCore_invalid)
+    ShouldOverrideCore = true;
   if (GetTriple().getArch() == llvm::Triple::arm &&
-      other.GetTriple().getArch() == llvm::Triple::arm &&
-      IsCompatibleMatch(other) && GetCore() == ArchSpec::eCore_arm_generic &&
-      other.GetCore() != ArchSpec::eCore_arm_generic) {
+    other.GetTriple().getArch() == llvm::Triple::arm &&
+    IsCompatibleMatch(other) && GetCore() == ArchSpec::eCore_arm_generic &&
+    other.GetCore() != ArchSpec::eCore_arm_generic)
+    ShouldOverrideCore = true;
+  if (ShouldOverrideCore) {
     m_core = other.GetCore();
     CoreUpdated(true);
   }
+
+  if (GetTriple().getVendor() == llvm::Triple::UnknownVendor)
+    GetTriple().setVendor(other.GetTriple().getVendor());
+
+  if (GetTriple().getOS() == llvm::Triple::UnknownOS)
+    GetTriple().setOS(other.GetTriple().getOS());
+
+  if (GetTriple().getArch() == llvm::Triple::UnknownArch)
+    GetTriple().setArch(other.GetTriple().getArch());
+
+  if (GetTriple().getEnvironment() == llvm::Triple::UnknownEnvironment)
+    GetTriple().setEnvironment(other.GetTriple().getEnvironment());
 }
 
 bool ArchSpec::SetArchitecture(ArchitectureType arch_type, uint32_t cpu,
