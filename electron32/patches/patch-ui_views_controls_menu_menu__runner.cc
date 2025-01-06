$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/controls/menu/menu_runner.cc.orig	2024-10-18 12:35:12.832227200 +0000
+++ ui/views/controls/menu/menu_runner.cc
@@ -89,7 +89,7 @@ void MenuRunner::RunMenuAt(
   }
 
   impl_->RunMenuAt(parent, button_controller, bounds, anchor, run_types_,
-                   native_view_for_gestures, corners,
+                   source_type, native_view_for_gestures, corners,
                    std::move(show_menu_host_duration_histogram));
 }
 
