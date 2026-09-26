$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc.orig	2026-09-17 03:47:47.000000000 +0000
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc
@@ -30,8 +30,8 @@
 #include "iamf/obu/decoder_config/opus_decoder_config.h"
 #include "iamf/obu/substream_channel_count.h"
 #include "iamf/obu/types.h"
-#include "include/opus.h"
-#include "include/opus_types.h"
+#include "third_party/opus/src/include/opus.h"
+#include "third_party/opus/src/include/opus_types.h"
 
 namespace iamf_tools {
 
