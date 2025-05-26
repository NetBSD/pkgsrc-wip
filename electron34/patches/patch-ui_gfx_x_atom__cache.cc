$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gfx/x/atom_cache.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gfx/x/atom_cache.cc
@@ -155,6 +155,7 @@ constexpr auto kAtomsToCache = std::to_a
     "application/octet-stream",
     "application/vnd.chromium.test",
     "chromium/filename",
+    "chromium/from-privileged",
     "chromium/x-bookmark-entries",
     "chromium/x-browser-actions",
     "chromium/x-file-system-files",
