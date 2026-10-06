$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/command_buffer/service/gles2_cmd_decoder.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/command_buffer/service/gles2_cmd_decoder.cc
@@ -2874,7 +2874,7 @@ GLES2Decoder* GLES2Decoder::Create(
   }
 
 // Allow linux to run fuzzers.
-#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return new GLES2DecoderImpl(client, command_buffer_service, outputter, group);
 #else
   LOG(FATAL) << "Validating command decoder is not supported.";
@@ -3285,6 +3285,13 @@ gpu::ContextResult GLES2DecoderImpl::Ini
     }
   }
 
+  if (feature_info_->context_type() == CONTEXT_TYPE_WEBGL2) {
+    // If WebGL 2, the PRIMITIVE_RESTART_FIXED_INDEX should be always enabled.
+    // See the section <Primitive Restart is Always Enabled> in WebGL 2 spec:
+    // https://www.khronos.org/registry/webgl/specs/latest/2.0/#4.1.4
+    DoEnable(GL_PRIMITIVE_RESTART_FIXED_INDEX);
+  }
+
   if (group_->gpu_preferences().enable_gpu_driver_debug_logging &&
       feature_info_->feature_flags().khr_debug) {
     InitializeGLDebugLogging(true, GLDebugMessageCallback, &logger_);
