$NetBSD$

From graphics/simp-3.5.1:

Apply https://github.com/gfx-rs/wgpu/pull/5166

$ halloy
thread 'main' panicked at /usr/pkgsrc/wip/halloy/work/vendor/wgpu-core-0.19.4/src/instance.rs:521:39:
called `Option::unwrap()` on a `None` value
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

--- ../vendor/wgpu-0.19.4/src/lib.rs.orig
+++ ../vendor/wgpu-0.19.4/src/lib.rs
@@ -2812,7 +2812,7 @@ pub struct CreateSurfaceError {
 enum CreateSurfaceErrorKind {
     /// Error from [`wgpu_hal`].
     #[cfg(wgpu_core)]
-    Hal(hal::InstanceError),
+    Hal(wgc::instance::CreateSurfaceError),
 
     /// Error from WebGPU surface creation.
     #[allow(dead_code)] // may be unused depending on target and features
@@ -2847,8 +2847,8 @@ impl error::Error for CreateSurfaceError
 }
 
 #[cfg(wgpu_core)]
-impl From<hal::InstanceError> for CreateSurfaceError {
-    fn from(e: hal::InstanceError) -> Self {
+impl From<wgc::instance::CreateSurfaceError> for CreateSurfaceError {
+    fn from(e: wgc::instance::CreateSurfaceError) -> Self {
         Self {
             inner: CreateSurfaceErrorKind::Hal(e),
         }
