$NetBSD$

--- lib/Basic/Targets.cpp.orig	2017-05-31 16:58:37.000000000 +0000
+++ lib/Basic/Targets.cpp
@@ -514,6 +514,8 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
 
     switch (Triple.getArch()) {
     default:
@@ -530,6 +532,15 @@ public:
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
 
