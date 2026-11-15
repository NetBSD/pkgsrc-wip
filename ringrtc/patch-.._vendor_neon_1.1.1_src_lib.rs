$NetBSD$

* Imported from FreeBSD

--- ../vendor/neon-1.1.1/src/lib.rs.orig	2026-11-12 18:57:28.952576540 +0100
+++ ../vendor/neon-1.1.1/src/lib.rs	2026-11-12 18:57:48.861390957 +0100
@@ -1,3 +1,5 @@
+#![feature(used_with_arg)]
+
 //! The [Neon][neon] crate provides bindings for writing [Node.js addons][addons]
 //! (i.e., dynamically-loaded binary modules) with a safe and fast Rust API.
 //!
