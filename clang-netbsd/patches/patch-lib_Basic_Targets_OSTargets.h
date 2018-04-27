$NetBSD$

--- lib/Basic/Targets/OSTargets.h.orig	2018-04-27 13:37:59.000000000 +0000
+++ lib/Basic/Targets/OSTargets.h
@@ -364,12 +364,23 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
   }
 
 public:
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
 
