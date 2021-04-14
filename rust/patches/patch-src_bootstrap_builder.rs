$NetBSD: patch-src_bootstrap_builder.rs,v 1.11 2020/07/06 13:56:32 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.

Fix RPATH for pkgsrc.

Workaround for building 1.51 with 1.51 bootstrap.

--- src/bootstrap/builder.rs.orig	2021-03-23 16:15:10.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -482,7 +482,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
             Kind::Run => describe!(run::ExpandYamlAnchors, run::BuildManifest),
@@ -1088,7 +1087,7 @@ impl<'a> Builder<'a> {
                 rustflags.arg("-Zosx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,/usr/pkg/lib")
             } else {
                 None
             };
@@ -1490,7 +1489,7 @@ impl<'a> Builder<'a> {
                 for el in stack.iter().rev() {
                     out += &format!("\t{:?}\n", el);
                 }
-                panic!(out);
+                std::panic::panic_any(out);
             }
             if let Some(out) = self.cache.get(&step) {
                 self.verbose(&format!("{}c {:?}", "  ".repeat(stack.len()), step));
