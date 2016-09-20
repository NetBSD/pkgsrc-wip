$NetBSD$

--- source/Host/netbsd/Host.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Host/netbsd/Host.cpp
@@ -110,7 +110,7 @@ static bool GetNetBSDProcessArgs(const P
     if (!cstr)
       break;
 
-    proc_args.AppendArgument(cstr);
+    proc_args.AppendArgument(llvm::StringRef(cstr));
   }
 
   return true;
