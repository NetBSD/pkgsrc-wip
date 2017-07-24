$NetBSD$

--- lib/Basic/Targets/OSTargets.h.orig	2017-07-24 13:42:56.662132868 +0000
+++ lib/Basic/Targets/OSTargets.h
@@ -365,6 +365,8 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
 
     switch (Triple.getArch()) {
     default:
@@ -382,6 +384,15 @@ public:
   NetBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
       : OSTargetInfo<Target>(Triple, Opts) {
     this->MCountName = "_mcount";
+
+    switch (Triple.getArch()) {
+    default:
+      break;
+    case llvm::Triple::x86:
+    case llvm::Triple::x86_64:
+      this->HasFloat128 = true;
+      break;
+    }
   }
 };
 
