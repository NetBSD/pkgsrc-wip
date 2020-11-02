$NetBSD$

--- src/channel_player.rs.orig	2020-09-25 18:46:41.000000000 +0000
+++ src/channel_player.rs
@@ -165,7 +165,7 @@ fn prepare_video_overlay(video_area: &gt
     let display_type_name = gdk_window.get_display().get_type().name();
 
     // Check if we're using X11 or ...
-    #[cfg(target_os = "linux")]
+    #[cfg(not(target_os = "macos"))]
     {
         // Check if we're using X11 or ...
         if display_type_name == "GdkX11Display" {
@@ -199,9 +199,6 @@ fn prepare_video_overlay(video_area: &gt
             process::exit(-1);
         }
     }
-
-    #[cfg(not(any(target_os = "linux", target_os = "macos")))]
-    unimplemented!();
 }
 
 impl PlayerDataHolder {
