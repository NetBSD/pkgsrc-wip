$NetBSD$

Add NetBSD support.

--- src/app/data/store.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/app/data/store.rs
@@ -261,24 +261,32 @@
                 }
                 #[cfg(not(target_os = "windows"))]
                 {
-                    #[cfg(any(feature = "zfs", target_os = "freebsd"))]
+                    #[cfg(target_os = "netbsd")]
                     {
-                        if !disk.name.starts_with('/') {
-                            Some(disk.name.as_str()) // use the whole name
-                        } else {
-                            #[cfg(target_os = "freebsd")]
-                            {
-                                Some(disk.mount_point.as_str()) // use mount_point for sysinfo
-                            }
-                            #[cfg(not(target_os = "freebsd"))]
-                            {
-                                disk.name.split('/').next_back() // use device name
-                            }
-                        }
+                        // NetBSD with sysinfo: always use mount_point since that's how get_io_usage keys the data
+                        Some(disk.mount_point.as_str())
                     }
-                    #[cfg(not(any(feature = "zfs", target_os = "freebsd")))]
+                    #[cfg(not(target_os = "netbsd"))]
                     {
-                        disk.name.split('/').next_back()
+                        #[cfg(any(feature = "zfs", target_os = "freebsd"))]
+                        {
+                            if !disk.name.starts_with('/') {
+                                Some(disk.name.as_str()) // use the whole name
+                            } else {
+                                #[cfg(target_os = "freebsd")]
+                                {
+                                    Some(disk.mount_point.as_str()) // use mount_point for sysinfo
+                                }
+                                #[cfg(not(target_os = "freebsd"))]
+                                {
+                                    disk.name.split('/').next_back() // use device name
+                                }
+                            }
+                        }
+                        #[cfg(not(any(feature = "zfs", target_os = "freebsd")))]
+                        {
+                            disk.name.split('/').next_back()
+                        }
                     }
                 }
             }) else {
