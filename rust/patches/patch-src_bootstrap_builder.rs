$NetBSD: patch-src_bootstrap_builder.rs,v 1.11 2020/07/06 13:56:32 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2022-06-27 13:37:07.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -743,7 +743,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
             Kind::Run => describe!(run::ExpandYamlAnchors, run::BuildManifest, run::BumpStage0),
@@ -1702,7 +1701,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
