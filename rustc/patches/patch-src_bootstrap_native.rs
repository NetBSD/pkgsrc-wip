$NetBSD$
¯\(°_o)/¯

--- src/bootstrap/native.rs.orig	2017-02-09 01:37:48.000000000 +0000
+++ src/bootstrap/native.rs
@@ -124,6 +124,8 @@ pub fn llvm(build: &Build, target: &str)
         cfg.define("CMAKE_CXX_FLAGS", build.cflags(target).join(" "));
     }
 
+    cfg.define("CMAKE_INSTALL_RPATH", "");
+
     // FIXME: we don't actually need to build all LLVM tools and all LLVM
     //        libraries here, e.g. we just want a few components and a few
     //        tools. Figure out how to filter them down and only build the right
