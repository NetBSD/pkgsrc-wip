$NetBSD$

--- components/capnp_conv/capnp_conv_derive/src/lib.rs.orig	2020-06-30 18:11:35.000000000 +0000
+++ components/capnp_conv/capnp_conv_derive/src/lib.rs
@@ -1,7 +1,7 @@
 #![crate_type = "lib"]
 #![recursion_limit = "128"]
 #![deny(trivial_numeric_casts, warnings)]
-#![allow(intra_doc_link_resolution_failure)]
+#![allow(broken_intra_doc_links)]
 #![allow(
     clippy::too_many_arguments,
     clippy::implicit_hasher,
