$NetBSD$

--- components/funder/src/lib.rs.orig	2020-06-30 18:11:35.000000000 +0000
+++ components/funder/src/lib.rs
@@ -1,7 +1,7 @@
 #![crate_type = "lib"]
 #![cfg_attr(not(feature = "cargo-clippy"), allow(unknown_lints))]
 #![deny(trivial_numeric_casts, warnings)]
-#![allow(intra_doc_link_resolution_failure)]
+#![allow(allow_broken_intra_doc_links)]
 #![allow(
     clippy::too_many_arguments,
     clippy::implicit_hasher,
