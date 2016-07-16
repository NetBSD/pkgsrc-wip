$NetBSD$

Apply upstream commit https://github.com/rust-lang/rust/commit/14b6c6d153edec5731230f919eaafcb5c32959d8
addressing https://github.com/rust-lang/rust/issues/20777 to NetBSD too.

--- src/librustc_back/target/x86_64_unknown_netbsd.rs.orig	2016-07-04 18:04:09.000000000 +0000
+++ src/librustc_back/target/x86_64_unknown_netbsd.rs
@@ -12,6 +12,7 @@ use target::Target;
 
 pub fn target() -> Target {
     let mut base = super::netbsd_base::opts();
+    base.cpu = "x86-64".to_string();
     base.max_atomic_width = 64;
     base.pre_link_args.push("-m64".to_string());
 
