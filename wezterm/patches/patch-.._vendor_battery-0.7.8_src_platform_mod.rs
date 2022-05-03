$NetBSD$

--- ../vendor/battery-0.7.8/src/platform/mod.rs.orig	2022-05-03 23:01:26.871498635 +0200
+++ ../vendor/battery-0.7.8/src/platform/mod.rs	2022-05-03 23:02:10.195004362 +0200
@@ -17,7 +17,7 @@
         pub type Manager = windows::PowerManager;
         pub type Iterator = windows::PowerIterator;
         pub type Device = windows::PowerDevice;
-    } else if #[cfg(any(target_os = "dragonfly", target_os = "freebsd"))] {
+    } else if #[cfg(any(target_os = "dragonfly", target_os = "freebsd", target_os = "netbsd"))] {
         mod freebsd;
 
         pub type Manager = freebsd::IoCtlManager;
