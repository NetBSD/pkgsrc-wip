$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/shell_dialogs/select_file_dialog_linux.h.orig	2024-10-18 12:35:12.788244700 +0000
+++ ui/shell_dialogs/select_file_dialog_linux.h
@@ -33,6 +33,12 @@ class SHELL_DIALOGS_EXPORT SelectFileDia
   // BaseShellDialog implementation.
   void ListenerDestroyed() override;
 
+  // SelectFileDialog:
+  void SetButtonLabel(const std::string& label) override;
+  void SetOverwriteConfirmationShown(bool is_shown) override;
+  void SetHiddenShown(bool is_shown) override;
+  void SetMultipleSelectionsAllowed(bool is_allowed) override;
+
  protected:
   explicit SelectFileDialogLinux(Listener* listener,
                                  std::unique_ptr<ui::SelectFilePolicy> policy);
@@ -77,6 +83,11 @@ class SHELL_DIALOGS_EXPORT SelectFileDia
     *last_opened_path_ = last_opened_path;
   }
 
+  const std::string& button_label() { return button_label_; }
+  bool show_overwrite_confirmation() { return show_overwrite_confirmation_; }
+  bool show_hidden() { return show_hidden_; }
+  bool allow_multiple_selection() { return allow_multiple_selection_; }
+
  private:
   // The file filters.
   FileTypeInfo file_types_;
@@ -92,6 +103,11 @@ class SHELL_DIALOGS_EXPORT SelectFileDia
   // file so that we can display future dialogs with the same starting path.
   static base::FilePath* last_saved_path_;
   static base::FilePath* last_opened_path_;
+
+  std::string button_label_;
+  bool show_overwrite_confirmation_ = true;
+  bool show_hidden_ = false;
+  bool allow_multiple_selection_ = false;
 };
 
 }  // namespace ui
