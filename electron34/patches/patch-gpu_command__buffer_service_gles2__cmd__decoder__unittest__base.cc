$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/command_buffer/service/gles2_cmd_decoder_unittest_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gpu/command_buffer/service/gles2_cmd_decoder_unittest_base.cc
@@ -440,6 +440,13 @@ ContextResult GLES2DecoderTestBase::Mayb
   }
 #endif
 
+  if (init.context_type == CONTEXT_TYPE_WEBGL2 &&
+      group_->feature_info()->gl_version_info().is_es3) {
+    EXPECT_CALL(*gl_, Enable(GL_PRIMITIVE_RESTART_FIXED_INDEX))
+        .Times(1)
+        .RetiresOnSaturation();
+  }
+
   if (context_->HasRobustness()) {
     EXPECT_CALL(*gl_, GetGraphicsResetStatusARB())
         .WillOnce(Return(init.lose_context_on_init ? GL_GUILTY_CONTEXT_RESET_ARB
