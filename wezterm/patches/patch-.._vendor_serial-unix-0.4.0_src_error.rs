$NetBSD$

--- ../vendor/serial-unix-0.4.0/src/error.rs.orig	2021-05-18 08:27:01.969610797 +0000
+++ ../vendor/serial-unix-0.4.0/src/error.rs	2021-05-18 08:25:55.579023516 +0000
@@ -64,7 +64,7 @@
         __dfly_error()
     }
 
-    #[cfg(target_os = "openbsd")]
+    #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
     unsafe fn errno_location() -> *const c_int {
         extern { fn __errno() -> *const c_int; }
         __errno()
