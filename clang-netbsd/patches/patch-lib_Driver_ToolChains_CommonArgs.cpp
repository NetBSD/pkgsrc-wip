$NetBSD$

--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2018-01-18 07:53:42.722099826 +0000
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -555,6 +555,9 @@ void tools::linkSanitizerRuntimeDeps(con
   // Required for backtrace on some OSes
   if (TC.getTriple().getOS() == llvm::Triple::NetBSD)
     CmdArgs.push_back("-lexecinfo");
+  // Required for backtrace on some OSes
+  if (TC.getTriple().getOS() == llvm::Triple::NetBSD)
+    CmdArgs.push_back("-lkvm");
 }
 
 static void
