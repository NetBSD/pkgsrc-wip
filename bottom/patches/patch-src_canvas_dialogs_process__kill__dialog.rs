$NetBSD$

Add NetBSD support.

--- src/canvas/dialogs/process_kill_dialog.rs.orig	2026-06-22 06:25:54.000000000 +0000
+++ src/canvas/dialogs/process_kill_dialog.rs
@@ -2,7 +2,7 @@
 
 use std::time::Instant;
 
-#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use ratatui::widgets::ListState;
 use ratatui::{
     Frame,
@@ -11,7 +11,7 @@ use ratatui::{
     widgets::{Paragraph, Wrap},
 };
 
-#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
 use crate::canvas::components::scroll_bar::{
     ScrollBarArgs, dialog_scroll_bar_area, draw_scroll_bar,
 };
@@ -165,6 +165,44 @@ cfg_select! {
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
 
@@ -176,7 +214,7 @@ cfg_select! {
 /// Note that signals are not available for Windows.
 #[derive(Debug)]
 pub(crate) enum ButtonState {
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     Signals {
         state: ListState,
         last_button_draw_area: Rect,
@@ -240,7 +278,7 @@ impl ProcessKillDialog {
             let pids = state.pids;
 
             match button_state {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 ButtonState::Signals { state, .. } => {
                     use crate::utils::process_killer;
 
@@ -280,7 +318,7 @@ impl ProcessKillDialog {
                                     }
                                 }
                             }
-                            any(target_os = "linux", target_os = "macos", target_os = "freebsd") => {
+                            any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd") => {
                                 use crate::utils::process_killer;
 
                                 for pid in pids {
@@ -306,7 +344,7 @@ impl ProcessKillDialog {
     }
 
     pub fn on_char(&mut self, c: char) {
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         const MAX_KEY_TIMEOUT: std::time::Duration = std::time::Duration::from_secs(1);
 
         match c {
@@ -315,7 +353,7 @@ impl ProcessKillDialog {
             'k' => self.on_up_key(),
             'l' => self.on_right_key(),
             '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 if let Some(value) = c.to_digit(10)
                     && let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
                         button_state: ButtonState::Signals { state, .. },
@@ -364,7 +402,7 @@ impl ProcessKillDialog {
                 }
             }
             'g' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 {
                     if let Some(('g', last_press)) = self.last_char {
                         if last_press.elapsed() <= MAX_KEY_TIMEOUT {
@@ -380,7 +418,7 @@ impl ProcessKillDialog {
                 }
             }
             'G' => {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 self.go_to_last();
             }
             _ => {}
@@ -394,7 +432,7 @@ impl ProcessKillDialog {
     pub fn on_click(&mut self, x: u16, y: u16) -> bool {
         if let ProcessKillDialogState::Selecting(state) = &mut self.state {
             match &mut state.button_state {
-                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+                #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
                 ButtonState::Signals {
                     state,
                     last_button_draw_area,
@@ -460,7 +498,7 @@ impl ProcessKillDialog {
         }
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     fn scroll_up_by(state: &mut ListState, amount: usize) {
         if let Some(selected) = state.selected() {
             if let Some(new_position) = selected.checked_sub(amount) {
@@ -471,7 +509,7 @@ impl ProcessKillDialog {
         }
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     fn scroll_down_by(state: &mut ListState, amount: usize) {
         if let Some(selected) = state.selected() {
             let new_position = selected + amount;
@@ -487,7 +525,7 @@ impl ProcessKillDialog {
     pub fn on_up_key(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -501,7 +539,7 @@ impl ProcessKillDialog {
     pub fn on_down_key(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -515,7 +553,7 @@ impl ProcessKillDialog {
     pub fn on_page_up(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state:
                 ButtonState::Signals {
@@ -534,7 +572,7 @@ impl ProcessKillDialog {
     pub fn on_page_down(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state:
                 ButtonState::Signals {
@@ -552,7 +590,7 @@ impl ProcessKillDialog {
     pub fn go_to_first(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -565,7 +603,7 @@ impl ProcessKillDialog {
     pub fn go_to_last(&mut self) {
         self.last_char = None;
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
             button_state: ButtonState::Signals { state, .. },
             ..
@@ -587,7 +625,7 @@ impl ProcessKillDialog {
             }
         } else {
             cfg_select! {
-                any(target_os = "linux", target_os = "macos", target_os = "freebsd") => {
+                any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd") => {
                     ButtonState::Signals { state: ListState::default().with_selected(Some(DEFAULT_KILL_SIGNAL)), last_button_draw_area: Rect::default() }
                 }
                 _ => {
@@ -616,7 +654,7 @@ impl ProcessKillDialog {
         // FIXME: Not sure if we need this. We can probably handle this better in the
         // draw function later.
 
-        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+        #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
         {
             if let ProcessKillDialogState::Selecting(ProcessKillSelectingInner {
                 button_state: ButtonState::Signals { state, .. },
@@ -675,7 +713,7 @@ impl ProcessKillDialog {
             .wrap(Wrap { trim: true });
 
         let title = match button_state {
-            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
             ButtonState::Signals { .. } => {
                 Line::styled(" Select Signal ", styles.widget_title_style)
             }
@@ -691,7 +729,7 @@ impl ProcessKillDialog {
         let num_lines = text.line_count(block.inner(draw_area).width) as u16;
 
         match button_state {
-            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
+            #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
             ButtonState::Signals {
                 state,
                 last_button_draw_area,
