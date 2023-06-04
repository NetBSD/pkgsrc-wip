$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/KBShortcutsDialog.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/KBShortcutsDialog.cpp
@@ -54,7 +54,7 @@ KBShortcutsDialog::KBShortcutsDialog()
     main_sizer->SetSizeHints(this);
     this->CenterOnParent();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // workaround to correct pages layout
     book->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, [book](wxBookCtrlEvent& e) {
         book->GetPage(e.GetSelection())->Fit();
