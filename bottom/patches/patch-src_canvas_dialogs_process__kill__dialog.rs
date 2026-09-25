$NetBSD$

Add NetBSD support.

--- src/canvas/dialogs/process_kill_dialog.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/canvas/dialogs/process_kill_dialog.rs
@@ -2,7 +2,7 @@
 
 use std::time::Instant;
 
-#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use ratatui::widgets::ListState;
 use ratatui::{
     Frame,
@@ -11,7 +11,7 @@
     widgets::{Paragraph, Wrap},
 };
 
-#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use crate::canvas::components::scroll_bar::{
     ScrollBarArgs, dialog_scroll_bar_area, draw_scroll_bar,
 };
@@ -165,6 +165,44 @@
             "33: LIBRT",
         ];
     }
+    target_os = "netbsd" => {
+        const DEFAULT_KILL_SIGNAL: usize = 15;
+        const SIGNAL_TEXT: [&str; 33] = [
+            "0: Cancel",
+            "1: HUP",
+            "2: INT",
+            "3: QUIT",
+            "4: ILL",
+            "5: TRAP",
+            "6: ABRT",
+            "7: EMT",
+            "8: FPE",
+            "9: KILL",
+            "10: BUS",
+            "11: SEGV",
+            "12: SYS",
+            "13: PIPE",
+            "14: ALRM",
+            "15: TERM",
+            "16: URG",
+            "17: STOP",
+            "18: TSTP",
+            "19: CONT",
+            "20: CHLD",
+            "21: TTIN",
+            "22: TTOU",
+            "23: IO",
+            "24: XCPU",
+            "25: XFSZ",
+            "26: VTALRM",
+            "27: PROF",
+            "28: WINCH",
+            "29: INFO",
+            "30: USR1",
+            "31: USR2",
+            "32: PWR",
+        ];
+    }
     _ => {}
 }
 
@@ -176,7 +214,7 @@
 /// Note that signals are not available for Windows.
 #[derive(Debug)]
 pub(crate) enum ButtonState {
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     Signals {
         state: ListState,
         last_button_draw_area: Rect,
@@ -240,7 +278,7 @@
             let pids = state.pids;
 
             match button_state {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 ButtonState::Signals { state, .. } => {
                     use crate::utils::process_killer;
 
@@ -278,7 +316,7 @@
                                     }
                                 }
                             }
-                            any(target_os = "linux", target_os = "macos", target_os = "freebsd") => {
+                            any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd") => {
                                 use crate::utils::process_killer;
 
                                 for pid in pids {
@@ -315,7 +353,7 @@
     }
 
     pub fn on_char(&mut self, c: char) {
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         const MAX_KEY_TIMEOUT: std::time::Duration = std::time::Duration::from_secs(1);
 
         match c {
@@ -324,7 +362,7 @@
             'k' => self.on_up_key(),
             'l' => self.on_right_key(),
             '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 if let Some(value) = c.to_digit(10)
                     && let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
                         button_state: ButtonState::Signals { state, .. },
@@ -374,7 +412,7 @@
                 }
             }
             'g' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 {
                     if let Some(('g', last_press)) = self.last_char {
                         if last_press.elapsed() <= MAX_KEY_TIMEOUT {
@@ -390,7 +428,7 @@
                 }
             }
             'G' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 self.go_to_last();
             }
             _ => {}
@@ -404,7 +442,7 @@
     pub fn on_click(&mut self, x: u16, y: u16) -> bool {
         if let ProcessKillDialogState::Selecting(state) = &mut self.state {
             match &mut state.button_state {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 ButtonState::Signals {
                     state,
                     last_button_draw_area,
@@ -470,7 +508,7 @@
         }
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     fn scroll_up_by(state: &mut ListState, amount: usize) {
         if let Some(selected) = state.selected() {
             if let Some(new_position) = selected.checked_sub(amount) {
@@ -481,7 +519,7 @@
         }
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     fn scroll_down_by(state: &mut ListState, amount: usize) {
         if let Some(selected) = state.selected() {
             let new_position = selected + amount;
@@ -497,7 +535,7 @@
     pub fn on_up_key(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -511,7 +549,7 @@
     pub fn on_down_key(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -525,7 +563,7 @@
     pub fn on_page_up(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state:
                 ButtonState::Signals {
@@ -544,7 +582,7 @@
     pub fn on_page_down(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state:
                 ButtonState::Signals {
@@ -562,7 +600,7 @@
     pub fn go_to_first(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -575,7 +613,7 @@
     pub fn go_to_last(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -597,7 +635,7 @@
             }
         } else {
             cfg_select! {
-                any(target_os = "linux", target_os = "macos", target_os = "freebsd") => {
+                any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd") => {
                     ButtonState::Signals {
                         state: ListState::default().with_selected(Some(DEFAULT_KILL_SIGNAL)),
                         last_button_draw_area: Rect::default(),
@@ -631,7 +669,7 @@
         // FIXME: Not sure if we need this. We can probably handle this better
         // in the draw function later.
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         {
             if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
                 button_state: ButtonState::Signals { state, .. },
@@ -690,7 +728,7 @@
             .wrap(Wrap { trim: true });
 
         let title = match button_state {
-            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
             ButtonState::Signals { .. } => {
                 Line::styled(" Select Signal ", styles.widget_title_style)
             }
@@ -706,7 +744,7 @@
         let num_lines = text.line_count(block.inner(draw_area).width) as u16;
 
         match button_state {
-            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
             ButtonState::Signals {
                 state,
                 last_button_draw_area,
@@ -917,7 +955,7 @@
 /// Return the signal number to send given the index on a list.
 ///
 /// On Linux, we need to skip 32 and 33, so we add 2 to the index if it's >= 32.
-#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 fn get_signal_from_index(index: usize) -> usize {
     if cfg!(target_os = "linux") && index >= 32 {
         index + 2
@@ -928,7 +966,7 @@
 
 #[cfg(test)]
 mod tests {
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     use super::*;
 
     #[test]
@@ -942,7 +980,7 @@
     }
 
     #[test]
-    #[cfg(any(target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     fn test_getting_signal_from_index_not_on_linux() {
         assert_eq!(get_signal_from_index(0), 0);
         assert_eq!(get_signal_from_index(31), 31);
