$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.h.orig	2026-09-07 10:14:27.000000000 +0000
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.h
@@ -23,7 +23,7 @@
 #include "iamf/cli/codec/decoder_base.h"
 #include "iamf/obu/decoder_config/opus_decoder_config.h"
 #include "iamf/obu/substream_channel_count.h"
-#include "include/opus.h"
+#include "third_party/opus/src/include/opus.h"
 
 namespace iamf_tools {
 
