$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ash/display/mirror_window_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ash/display/mirror_window_controller.cc
@@ -295,7 +295,11 @@ void MirrorWindowController::UpdateWindo
       if (!base::Contains(display_info_list, iter->first,
                           &display::ManagedDisplayInfo::id)) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
