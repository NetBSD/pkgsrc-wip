$NetBSD$

* Add Free- and NetBSD support

--- src/rust/src/webrtc/audio_device_module_utils.rs.orig	2026-11-12 15:55:51.237475582 +0000
+++ src/rust/src/webrtc/audio_device_module_utils.rs
@@ -14,7 +14,7 @@ use std::{
 
 use anyhow::anyhow;
 use cubeb::{DeviceCollection, DeviceState};
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
 use cubeb_core::DeviceType;
 use cubeb_core::{DeviceId, DevicePref};
 
@@ -30,7 +30,7 @@ pub struct MinimalDeviceInfo {
     pub devid: DeviceId,
     pub device_id: String,
     pub friendly_name: String,
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
     device_type: DeviceType,
     preferred: DevicePref,
     state: DeviceState,
@@ -48,7 +48,7 @@ pub struct DeviceCollectionWrapper {
     device_collection: Vec<MinimalDeviceInfo>,
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
 fn device_is_monitor(device: &MinimalDeviceInfo) -> bool {
     device.device_type == DeviceType::INPUT && device.device_id.ends_with(".monitor")
 }
@@ -66,7 +66,7 @@ impl DeviceCollectionWrapper {
                     devid: device.devid(),
                     device_id: device_id.to_string(),
                     friendly_name: friendly.to_string(),
-                    #[cfg(target_os = "linux")]
+                    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
                     device_type: device.device_type(),
                     preferred: device.preferred(),
                     state: device.state(),
@@ -94,7 +94,7 @@ impl DeviceCollectionWrapper {
     }
 
     // For linux only, a method that will ignore "monitor" devices.
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
     pub fn iter_non_monitor(
         &self,
     ) -> std::iter::Filter<std::slice::Iter<'_, MinimalDeviceInfo>, fn(&&MinimalDeviceInfo) -> bool>
@@ -136,7 +136,7 @@ impl DeviceCollectionWrapper {
             {
                 self.iter().nth(idx - 1)
             }
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
             {
                 // filter out "monitor" devices.
                 self.iter_non_monitor().nth(idx - 1)
@@ -164,12 +164,12 @@ impl DeviceCollectionWrapper {
     pub fn count(&self) -> usize {
         #[cfg(target_os = "macos")]
         let count = self.iter().count();
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
         let count = self.iter_non_monitor().count();
         if count == 0 {
             #[cfg(target_os = "macos")]
             return 0;
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "netbsd"))]
             return
                 // edge case: if there are only monitor devices, and one is the default,
                 // allow it.
