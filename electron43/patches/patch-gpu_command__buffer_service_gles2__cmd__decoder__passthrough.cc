$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/command_buffer/service/gles2_cmd_decoder_passthrough.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/command_buffer/service/gles2_cmd_decoder_passthrough.cc
@@ -1065,6 +1065,17 @@ gpu::ContextResult GLES2DecoderPassthrou
     api()->glDisableFn(GL_TEXTURE_RECTANGLE_ANGLE);
 #endif
 
+  // TEMPORARY: Set primitive restart to enabled by default for WebGL2. Clear
+  // errors afterwards so that when this state is initialized and validated in
+  // ANGLE, it will not generate errors during command buffer initialization.
+  if (feature_info_->context_type() == CONTEXT_TYPE_WEBGL2) {
+    // If WebGL 2, the PRIMITIVE_RESTART_FIXED_INDEX should be always enabled.
+    // See the section <Primitive Restart is Always Enabled> in WebGL 2 spec:
+    // https://www.khronos.org/registry/webgl/specs/latest/2.0/#4.1.4
+    api()->glEnableFn(GL_PRIMITIVE_RESTART_FIXED_INDEX);
+    CheckErrorCallbackState();
+  }
+
   // Register this object as a GPU switching observer.
   if (feature_info_->IsWebGLContext()) {
     ui::GpuSwitchingManager::GetInstance()->AddObserver(this);
@@ -2160,6 +2171,11 @@ bool GLES2DecoderPassthroughImpl::IsIgno
     case GL_DEBUG_OUTPUT:
       return true;
 
+    case GL_PRIMITIVE_RESTART_FIXED_INDEX:
+      // Disable setting primitive restart at the command decoder level until
+      // it's blocked in ANGLE for WebGL contexts.
+      return feature_info_->IsWebGLContext();
+
     default:
       return false;
   }
