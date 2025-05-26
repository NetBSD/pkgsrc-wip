$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/controls/menu/menu_runner.cc
@@ -90,7 +90,7 @@ void MenuRunner::RunMenuAt(
   }
 
   impl_->RunMenuAt(parent, button_controller, bounds, anchor, run_types_,
-                   native_view_for_gestures, corners,
+                   source_type, native_view_for_gestures, corners,
                    std::move(show_menu_host_duration_histogram));
 }
 
