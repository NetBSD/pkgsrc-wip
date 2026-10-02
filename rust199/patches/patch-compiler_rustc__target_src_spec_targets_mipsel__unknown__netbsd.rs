$NetBSD: patch-compiler_rustc__target_src_spec_targets_mipsel__unknown__netbsd.rs,v 1.3 2025/08/25 17:51:12 wiz Exp $

Let's see if turning off thread local storage makes a difference...

--- compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs.orig	2024-08-05 20:02:56.368978562 +0000
+++ compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs
@@ -24,6 +24,7 @@ pub(crate) fn target() -> Target {
             llvm_args: cvs!["-mno-check-zero-division"],
             mcount: "__mcount".into(),
             endian: Endian::Little,
+            has_thread_local: false,
             ..base
         },
     }
