$NetBSD$

--- components/timer/src/timer.rs.orig	2020-06-30 18:11:35.000000000 +0000
+++ components/timer/src/timer.rs
@@ -20,7 +20,7 @@
 //! [futures]: https://github.com/alexcrichton/futures
 //! [futures-timer]: https://github.com/alexcrichton/futures-timer
 
-#![allow(intra_doc_link_resolution_failure)]
+#![allow(broken_intra_doc_links)]
 #![allow(clippy::implicit_hasher, clippy::module_inception)]
 
 use common::conn::BoxStream;
