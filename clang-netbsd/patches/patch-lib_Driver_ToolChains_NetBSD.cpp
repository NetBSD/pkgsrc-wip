$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-03-18 00:58:03.000000000 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -239,6 +239,7 @@ void netbsd::Linker::ConstructJob(Compil
   }
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
+  getToolChain().AddFilePathLibArgs(Args, CmdArgs);
   Args.AddAllArgs(CmdArgs, options::OPT_T_Group);
   Args.AddAllArgs(CmdArgs, options::OPT_e);
   Args.AddAllArgs(CmdArgs, options::OPT_s);
@@ -326,9 +327,12 @@ NetBSD::NetBSD(const Driver &D, const ll
     // doesn't work.
     // FIXME: It'd be nicer to test if this directory exists, but I'm not sure
     // what all logic is needed to emulate the '=' prefix here.
+    auto AddPath = [&](StringRef Path) {
+      getFilePaths().push_back(getDriver().SysRoot + Path.str());
+    };
     switch (Triple.getArch()) {
     case llvm::Triple::x86:
-      getFilePaths().push_back("=/usr/lib/i386");
+      AddPath("/usr/lib/i386");
       break;
     case llvm::Triple::arm:
     case llvm::Triple::armeb:
@@ -337,35 +341,34 @@ NetBSD::NetBSD(const Driver &D, const ll
       switch (Triple.getEnvironment()) {
       case llvm::Triple::EABI:
       case llvm::Triple::GNUEABI:
-        getFilePaths().push_back("=/usr/lib/eabi");
+        AddPath("/usr/lib/eabi");
         break;
       case llvm::Triple::EABIHF:
       case llvm::Triple::GNUEABIHF:
-        getFilePaths().push_back("=/usr/lib/eabihf");
+        AddPath("/usr/lib/eabihf");
         break;
       default:
-        getFilePaths().push_back("=/usr/lib/oabi");
+        AddPath("/usr/lib/oabi");
         break;
       }
       break;
     case llvm::Triple::mips64:
     case llvm::Triple::mips64el:
       if (tools::mips::hasMipsAbiArg(Args, "o32"))
-        getFilePaths().push_back("=/usr/lib/o32");
+        AddPath("/usr/lib/o32");
       else if (tools::mips::hasMipsAbiArg(Args, "64"))
-        getFilePaths().push_back("=/usr/lib/64");
+        AddPath("/usr/lib/64");
       break;
     case llvm::Triple::ppc:
-      getFilePaths().push_back("=/usr/lib/powerpc");
+      AddPath("/usr/lib/powerpc");
       break;
     case llvm::Triple::sparc:
-      getFilePaths().push_back("=/usr/lib/sparc");
+      AddPath("/usr/lib/sparc");
       break;
     default:
       break;
     }
-
-    getFilePaths().push_back("=/usr/lib");
+    AddPath("/usr/lib");
   }
 }
 
