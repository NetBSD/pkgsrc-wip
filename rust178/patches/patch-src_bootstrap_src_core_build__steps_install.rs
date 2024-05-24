$NetBSD$

Install docs into "rust" directory, as versions prior 1.78.0 did.

--- src/bootstrap//src/core/build_steps/install.rs.orig	2024-05-24 12:04:39.240454631 +0000
+++ src/bootstrap//src/core/build_steps/install.rs
@@ -200,7 +200,7 @@ macro_rules! install {
 install!((self, builder, _config),
     Docs, path = "src/doc", _config.docs, only_hosts: false, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
-        install_sh(builder, "docs", self.compiler.stage, Some(self.target), &tarball);
+        install_sh(builder, "rust", self.compiler.stage, Some(self.target), &tarball);
     };
     Std, path = "library/std", true, only_hosts: false, {
         // `expect` should be safe, only None when host != build, but this
