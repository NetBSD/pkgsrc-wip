$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2024-08-06 19:54:58.766940000 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -143,6 +143,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(cons
     return EmbeddedTargetOs::kWin;
   } else if (string == "starboard") {
     return EmbeddedTargetOs::kStarboard;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
