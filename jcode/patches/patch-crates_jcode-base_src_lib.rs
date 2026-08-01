$NetBSD$

Declare the NetBSD process-memory module added by this patch set.

--- crates/jcode-base/src/lib.rs.orig
+++ crates/jcode-base/src/lib.rs
@@ -62,6 +62,8 @@ pub mod plan;
 pub mod platform;
 pub mod power_inhibit;
 pub mod process_memory;
+#[cfg(target_os = "netbsd")]
+mod process_memory_netbsd;
 pub mod process_title;
 pub mod prompt;
 pub mod protocol;
