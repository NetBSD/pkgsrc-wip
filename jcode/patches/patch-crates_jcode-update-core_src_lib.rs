$NetBSD$

Distinguish "no prebuilt binary for this platform" from a failed download.

There is no NetBSD release asset, so the self-updater reported a confusing
missing-asset error. Add platform_has_prebuilt_binary() so callers can say
"build from source" instead, and relax a test that assumed every platform
ships a binary.

--- crates/jcode-update-core/src/lib.rs.orig
+++ crates/jcode-update-core/src/lib.rs
@@ -138,6 +138,17 @@ pub fn update_estimate(summary: String, duration: Duration) -> UpdateEstimate {
     }
 }
 
+/// Sentinel returned by [`get_asset_name`] on platforms with no prebuilt
+/// release binary (the BSDs, for instance, which build from source).
+pub const UNSUPPORTED_ASSET_NAME: &str = "jcode-unknown";
+
+/// Whether this platform publishes a prebuilt release asset. When false,
+/// self-update cannot work and callers should say "build from source" rather
+/// than reporting a missing download.
+pub fn platform_has_prebuilt_binary() -> bool {
+    get_asset_name() != UNSUPPORTED_ASSET_NAME
+}
+
 pub fn get_asset_name() -> &'static str {
     #[cfg(all(target_os = "linux", target_arch = "x86_64"))]
     {
@@ -513,9 +524,23 @@ mod tests {
         )));
     }
 
+    /// Every platform we publish binaries for must map to a real asset. On
+    /// platforms built from source (the BSDs) the sentinel is the correct
+    /// answer, and `platform_has_prebuilt_binary` must agree with it.
     #[test]
-    fn asset_name_is_supported() {
-        assert_ne!(get_asset_name(), "jcode-unknown");
+    fn asset_name_matches_prebuilt_binary_availability() {
+        let name = get_asset_name();
+        assert!(name.starts_with("jcode-"), "unexpected asset name {name}");
+        assert_eq!(
+            platform_has_prebuilt_binary(),
+            name != UNSUPPORTED_ASSET_NAME
+        );
+
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "windows"))]
+        assert!(
+            platform_has_prebuilt_binary(),
+            "tier-1 platforms must have a release asset, got {name}"
+        );
     }
 
     #[test]
