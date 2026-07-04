$NetBSD$

Add NetBSD support.

--- src/app/data/store.rs.orig	2026-06-22 06:25:54.000000000 +0000
+++ src/app/data/store.rs
@@ -204,24 +204,32 @@ impl StoredData {
                 }
                 #[cfg(not(target_os = "windows"))]
                 {
-                    #[cfg(any(feature = "zfs", target_os = "freebsd"))]
+                    #[cfg(target_os = "netbsd")]
                     {
-                        if !device.name.starts_with('/') {
-                            Some(device.name.as_str()) // use the whole name
-                        } else {
-                            #[cfg(target_os = "freebsd")]
-                            {
-                                Some(device.mount_point.as_str()) // use mount_point for sysinfo
-                            }
-                            #[cfg(not(target_os = "freebsd"))]
-                            {
-                                device.name.split('/').next_back() // use device name
-                            }
-                        }
+                        // NetBSD with sysinfo: always use mount_point since that's how get_io_usage keys the data
+                        Some(device.mount_point.as_str())
                     }
-                    #[cfg(not(any(feature = "zfs", target_os = "freebsd")))]
+                    #[cfg(not(target_os = "netbsd"))]
                     {
-                        device.name.split('/').next_back()
+                        #[cfg(any(feature = "zfs", target_os = "freebsd"))]
+                        {
+                            if !device.name.starts_with('/') {
+                                Some(device.name.as_str()) // use the whole name
+                            } else {
+                                #[cfg(target_os = "freebsd")]
+                                {
+                                    Some(device.mount_point.as_str()) // use mount_point for sysinfo
+                                }
+                                #[cfg(not(target_os = "freebsd"))]
+                                {
+                                    device.name.split('/').next_back() // use device name
+                                }
+                            }
+                        }
+                        #[cfg(not(any(feature = "zfs", target_os = "freebsd")))]
+                        {
+                            device.name.split('/').next_back()
+                        }
                     }
                 }
             }) else {
