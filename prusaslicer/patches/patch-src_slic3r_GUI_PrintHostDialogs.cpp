$NetBSD$

Treat NetBSD like Linux.

Upstream fix for boost deprecations:
https://github.com/prusa3d/PrusaSlicer/issues/9294

--- src/slic3r/GUI/PrintHostDialogs.cpp.orig	2023-11-21 12:30:33.000000000 +0000
+++ src/slic3r/GUI/PrintHostDialogs.cpp
@@ -115,7 +115,7 @@ PrintHostSendDialog::PrintHostSendDialog
 
     auto* btn_ok = add_button(wxID_OK, true, _L("Upload"));
     btn_ok->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-        if (validate_path(txt_filename->GetValue())) {
+        if (validate_path(txt_filename->GetValue().ToStdWstring())) {
             post_upload_action = PrintHostPostUploadAction::None;
             EndDialog(wxID_OK);
         }
@@ -125,7 +125,7 @@ PrintHostSendDialog::PrintHostSendDialog
     if (post_actions.has(PrintHostPostUploadAction::QueuePrint)) {
         auto* btn_print = add_button(wxID_ADD, false, _L("Upload to Queue"));
         btn_print->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::QueuePrint;
                 EndDialog(wxID_OK);
             }
@@ -135,7 +135,7 @@ PrintHostSendDialog::PrintHostSendDialog
     if (post_actions.has(PrintHostPostUploadAction::StartPrint)) {
         auto* btn_print = add_button(wxID_YES, false, _L("Upload and Print"));
         btn_print->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::StartPrint;
                 EndDialog(wxID_OK);
             }
@@ -146,7 +146,7 @@ PrintHostSendDialog::PrintHostSendDialog
         // Using wxID_MORE as a button identifier to be different from the other buttons, wxID_MORE has no other meaning here.
         auto* btn_simulate = add_button(wxID_MORE, false, _L("Upload and Simulate"));
         btn_simulate->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::StartSimulation;
                 EndDialog(wxID_OK);
             }        
@@ -156,7 +156,7 @@ PrintHostSendDialog::PrintHostSendDialog
     add_button(wxID_CANCEL);
     finalize();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // On Linux with GTK2 when text control lose the focus then selection (colored background) disappears but text color stay white
     // and as a result the text is invisible with light mode
     // see https://github.com/prusa3d/PrusaSlicer/issues/4532
