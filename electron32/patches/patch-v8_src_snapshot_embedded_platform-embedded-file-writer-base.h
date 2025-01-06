$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2024-10-18 12:48:35.460421300 +0000
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -32,6 +32,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
