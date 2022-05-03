$NetBSD$

Remove update checker.

--- wezterm-gui/src/termwindow/mod.rs.orig
+++ wezterm-gui/src/termwindow/mod.rs
@@ -811,7 +811,6 @@ impl TermWindow {
             myself.emit_status_event();
         }
 
-        crate::update::start_update_checker();
         front_end().record_known_window(window, mux_window_id);
         Ok(())
     }