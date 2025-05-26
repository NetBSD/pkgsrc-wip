$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -1432,12 +1432,6 @@ void WebGLRenderingContextBase::Initiali
                             ->GetCapabilities()
                             .mesa_framebuffer_flip_y;
 
-  // If WebGL 2, the PRIMITIVE_RESTART_FIXED_INDEX should be always enabled.
-  // See the section <Primitive Restart is Always Enabled> in WebGL 2 spec:
-  // https://www.khronos.org/registry/webgl/specs/latest/2.0/#4.1.4
-  if (IsWebGL2())
-    ContextGL()->Enable(GL_PRIMITIVE_RESTART_FIXED_INDEX);
-
   // This ensures that the context has a valid "lastFlushID" and won't be
   // mistakenly identified as the "least recently used" context.
   ContextGL()->Flush();
@@ -6315,7 +6309,7 @@ void WebGLRenderingContextBase::TexImage
   constexpr bool kAllowZeroCopyImages = true;
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1175907): Only TexImage2D seems to work with the GPU path on
   // Android M -- appears to work fine on R, but to avoid regressions in <video>
   // limit to TexImage2D only for now. Fails conformance test on Nexus 5X:
