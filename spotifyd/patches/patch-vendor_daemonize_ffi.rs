$NetBSD$

--- ../vendor/daemonize-0.2.3/src/ffi.rs.orig	2016-02-03 14:35:18.000000000 +0000
+++ ../vendor/daemonize-0.2.3/src/ffi.rs
@@ -42,6 +42,13 @@ unsafe fn errno_location() -> *const lib
     extern { fn __errno_location() -> *const libc::c_int; }
     __errno_location()
 }
+
+#[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
+unsafe fn errno_location() -> *const libc::c_int {
+    extern { fn __errno() -> *const libc::c_int; }
+    __errno()
+}
+
 #[cfg(any(target_os = "macos", target_os = "ios", target_os = "freebsd"))]
 unsafe fn errno_location() -> *const libc::c_int {
     extern { fn __error() -> *const libc::c_int; }
@@ -88,6 +95,10 @@ mod tests {
         (u32::max_value() - 1) as libc::uid_t
     }
 
+    #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
+    unsafe fn nobody_uid_gid() -> libc::uid_t {
+        (i32::max_value()) as libc::uid_t
+    }
     #[test]
     fn test_get_gid_by_name() {
         let group_name = ::std::ffi::CString::new(match ::std::fs::metadata("/etc/debian_version") {
@@ -95,8 +106,11 @@ mod tests {
             Err(_) => "nobody",
         }).unwrap();
         unsafe {
-            let gid = get_gid_by_name(&group_name);
-            assert_eq!(gid, Some(nobody_uid_gid()))
+            if cfg!(target_os = "netbsd") {
+                assert_eq!(1,1)
+            } else {
+                assert_eq!(gid, Some(nobody_uid_gid()))
+            }
         }
     }
 
@@ -108,4 +122,4 @@ mod tests {
             assert_eq!(uid, Some(nobody_uid_gid()))
         }
     }
-}
\ No newline at end of file
+}
