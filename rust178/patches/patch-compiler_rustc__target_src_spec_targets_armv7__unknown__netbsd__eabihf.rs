$NetBSD$

Turn off use of thread local storage on 32-bit arm, due to
NetBSD PR#58550, which is fixed with
https://mail-index.netbsd.org/source-changes/2020/06/16/msg118407.html
but isn't present in netbsd-9, which presently has revisions 1.1-1.44 +
1.46, but not 1.45 which fixes htis problem.

--- compiler/rustc_target/src/spec/targets/armv7_unknown_netbsd_eabihf.rs.orig	2024-08-04 09:45:48.159906022 +0000
+++ compiler/rustc_target/src/spec/targets/armv7_unknown_netbsd_eabihf.rs
@@ -17,6 +17,7 @@ pub fn target() -> Target {
             features: "+v7,+vfp3,-d32,+thumb2,-neon".into(),
             max_atomic_width: Some(64),
             mcount: "__mcount".into(),
+            has_thread_local: false, // Attempt to get 9.0 working...
             ..base::netbsd::opts()
         },
     }
