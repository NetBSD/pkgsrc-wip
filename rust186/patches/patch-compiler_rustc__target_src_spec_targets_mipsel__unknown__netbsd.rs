$NetBSD$

Let's see if turning off thread local storage makes a difference...

--- compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs.orig	2024-08-05 20:02:56.368978562 +0000
+++ compiler/rustc_target/src/spec/targets/mipsel_unknown_netbsd.rs
@@ -21,6 +21,7 @@ pub fn target() -> Target {
             features: "+soft-float".into(),
             mcount: "__mcount".into(),
             endian: Endian::Little,
+            has_thread_local: false, // Let's see if there's a difference...
             ..base
         },
     }
