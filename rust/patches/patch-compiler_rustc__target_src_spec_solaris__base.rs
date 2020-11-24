$NetBSD$

Enable frame pointers on SunOS.

--- compiler/rustc_target/src/spec/solaris_base.rs.orig	2020-11-16 14:01:53.000000000 +0000
+++ compiler/rustc_target/src/spec/solaris_base.rs
@@ -7,6 +7,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         target_family: Some("unix".to_string()),
         is_like_solaris: true,
+        eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
         eh_frame_header: false,
 
