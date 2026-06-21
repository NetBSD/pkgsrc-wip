$NetBSD$

NetBSD specific functions

--- src/network.rs.orig	2026-06-18 08:00:54.000000000 +0000
+++ src/network.rs
@@ -231,6 +231,35 @@ fn parse_default_iface_from_netstat_json
     None
 }
 
+#[cfg(target_os = "netbsd")]
+fn get_default_interface(family: Option<IpFamily>) -> Option<String> {
+    let netstat_args: &[&str] = if family == Some(IpFamily::V6) {
+        &["-L", "-finet6", "-nr"]
+    } else {
+        &["-L", "-finet", "-nr"]
+    };
+
+    if let Ok(output) = Command::new("netstat").args(netstat_args).output() {
+        if output.status.success() {
+            if let Ok(output_str) = String::from_utf8(output.stdout) {
+                for line in output_str.lines() {
+                    let line = line.trim();
+                    if line.starts_with("default") {
+                        if let Some(iface) = line.split_whitespace().last() {
+                            let iface = iface.trim().to_string();
+                            if !iface.is_empty() {
+                                return Some(iface);
+                            }
+                        }
+                    }
+                }
+            }
+        }
+    }
+
+    None
+}
+
 #[cfg(target_os = "macos")]
 fn get_default_interface(family: Option<IpFamily>) -> Option<String> {
     // `route -n get -inet6 default` for IPv6; the v4 default otherwise.
@@ -357,6 +386,11 @@ fn check_if_wireless(iface: &str) -> Opt
     Some(is_wireless)
 }
 
+#[cfg(target_os = "netbsd")]
+fn check_if_wireless(_iface: &str) -> Option<bool> {
+    Some(false)
+}
+
 #[cfg(target_os = "macos")]
 fn check_if_wireless(iface: &str) -> Option<bool> {
     // Parse `networksetup -listallhardwareports` to check if the interface is Wi-Fi
@@ -477,6 +511,11 @@ fn get_wireless_ssid(iface: &str) -> Opt
     None
 }
 
+#[cfg(target_os = "netbsd")]
+fn get_wireless_ssid(_iface: &str) -> Option<String> {
+    None
+}
+
 #[cfg(target_os = "macos")]
 fn get_wireless_ssid(iface: &str) -> Option<String> {
     // Try `networksetup -getairportnetwork <iface>` (public API)
@@ -576,6 +615,26 @@ fn get_interface_mac(iface: &str) -> Opt
     None
 }
 
+#[cfg(target_os = "netbsd")]
+fn get_interface_mac(iface: &str) -> Option<String> {
+    // Use `ifconfig <iface>` and parse the `address` line
+    if let Ok(output) = Command::new("ifconfig").arg(iface).output() {
+        if output.status.success() {
+            if let Ok(output_str) = String::from_utf8(output.stdout) {
+                for line in output_str.lines() {
+                    let line = line.trim();
+                    if line.starts_with("address: ") {
+                        if let Some(mac) = line.split_whitespace().nth(1) {
+                            return Some(mac.to_string());
+                        }
+                    }
+                }
+            }
+        }
+    }
+    None
+}
+
 #[cfg(target_os = "windows")]
 fn get_interface_mac(iface: &str) -> Option<String> {
     let output = Command::new("powershell")
