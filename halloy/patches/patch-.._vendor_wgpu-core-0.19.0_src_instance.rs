$NetBSD$

From graphics/simp-3.5.1:

Apply https://github.com/gfx-rs/wgpu/pull/5166

$ halloy
thread 'main' panicked at /usr/pkgsrc/wip/halloy/work/vendor/wgpu-core-0.19.4/src/instance.rs:521:39:
called `Option::unwrap()` on a `None` value
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

--- ../vendor/wgpu-core-0.19.4/src/instance.rs.orig
+++ ../vendor/wgpu-core-0.19.4/src/instance.rs
@@ -467,6 +467,15 @@ pub enum RequestAdapterError {
     InvalidSurface(SurfaceId),
 }
 
+#[derive(Clone, Debug, Error)]
+#[non_exhaustive]
+pub enum CreateSurfaceError {
+    #[error("No backend is available")]
+    NoSupportedBackend,
+    #[error(transparent)]
+    InstanceError(#[from] hal::InstanceError),
+}
+
 impl<G: GlobalIdentityHandlerFactory> Global<G> {
     /// # Safety
     ///
@@ -479,7 +488,7 @@ impl<G: GlobalIdentityHandlerFactory> Gl
         display_handle: raw_window_handle::RawDisplayHandle,
         window_handle: raw_window_handle::RawWindowHandle,
         id_in: Input<G, SurfaceId>,
-    ) -> Result<SurfaceId, hal::InstanceError> {
+    ) -> Result<SurfaceId, CreateSurfaceError> {
         profiling::scope!("Instance::create_surface");
 
         fn init<A: HalApi>(
@@ -517,8 +526,7 @@ impl<G: GlobalIdentityHandlerFactory> Gl
             hal_surface = init::<hal::api::Gles>(&self.instance.gl, display_handle, window_handle);
         }
 
-        //  This is only None if there's no instance at all.
-        let hal_surface = hal_surface.unwrap()?;
+        let hal_surface = hal_surface.ok_or(CreateSurfaceError::NoSupportedBackend)??;
 
         let surface = Surface {
             presentation: Mutex::new(None),
