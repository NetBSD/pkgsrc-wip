$NetBSD$

--- source/Plugins/DynamicLoader/POSIX-DYLD/DynamicLoaderPOSIXDYLD.cpp.orig	2016-12-17 10:29:49.000000000 +0000
+++ source/Plugins/DynamicLoader/POSIX-DYLD/DynamicLoaderPOSIXDYLD.cpp
@@ -64,7 +64,8 @@ DynamicLoader *DynamicLoaderPOSIXDYLD::C
     const llvm::Triple &triple_ref =
         process->GetTarget().GetArchitecture().GetTriple();
     if (triple_ref.getOS() == llvm::Triple::Linux ||
-        triple_ref.getOS() == llvm::Triple::FreeBSD)
+        triple_ref.getOS() == llvm::Triple::FreeBSD ||
+        triple_ref.getOS() == llvm::Triple::NetBSD)
       create = true;
   }
 
