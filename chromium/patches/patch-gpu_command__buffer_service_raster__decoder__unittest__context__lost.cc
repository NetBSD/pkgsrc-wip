$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc
@@ -15,6 +15,18 @@ using ::testing::Return;
 using ::testing::SaveArg;
 using ::testing::SetArrayArgument;
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
+#ifndef GL_GUILTY_CONTEXT_RESET_KHR
+#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
+#endif
+
+#ifndef GL_INNOCENT_CONTEXT_RESET_KHR
+#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
+#endif
+
 namespace gpu {
 namespace raster {
 
