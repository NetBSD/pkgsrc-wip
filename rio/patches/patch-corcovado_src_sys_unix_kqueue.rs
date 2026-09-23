$NetBSD$

NetBSD kevent.udata is *mut c_void, not intptr_t.

--- corcovado/src/sys/unix/kqueue.rs.orig
+++ corcovado/src/sys/unix/kqueue.rs
@@ -32,7 +32,7 @@
 #[cfg(target_os = "netbsd")]
 type Filter = u32;
 #[cfg(target_os = "netbsd")]
-type UData = ::libc::intptr_t;
+type UData = *mut ::libc::c_void;
 #[cfg(target_os = "netbsd")]
 type Count = usize;
 
