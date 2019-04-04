$NetBSD$

For the nobody uid it's the same as OpenBSD. For the gid, however, it's
a bit different. You can't guarantee the gid is going to be the same
"max value" as per the uid for the nobody user. On my two amd64 NetBSD 8
systems the nobody user is listed as:

nobody:*:32767:39:Unprivileged user:/nonexistent:/sbin/nologin

But I don't _think_ that 39 is going to be guaranteed everywhere.
Therefore simplest solution seems to be to skip this test on NetBSD.

Not submitted upstream because unsure about the gid issue.


--- ../vendor/daemonize-0.3.0/src/ffi.rs.orig	2018-03-19 18:50:44.000000000 +0000
+++ ../vendor/daemonize-0.3.0/src/ffi.rs
@@ -79,6 +79,11 @@ mod tests {
         (i16::max_value()) as libc::uid_t
     }
 
+    #[cfg(target_os = "netbsd")]
+    unsafe fn nobody_uid_gid() -> libc::uid_t {
+        (i32::max_value()) as libc::uid_t
+    }
+
     #[test]
     fn test_get_gid_by_name() {
         let group_name = ::std::ffi::CString::new(match ::std::fs::metadata("/etc/debian_version") {
@@ -86,8 +91,11 @@ mod tests {
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
 
