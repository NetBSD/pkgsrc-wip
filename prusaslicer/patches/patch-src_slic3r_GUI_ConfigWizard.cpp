$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ConfigWizard.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/ConfigWizard.cpp
@@ -48,7 +48,7 @@
 #include "MsgDialog.hpp"
 #include "UnsavedChangesDialog.hpp"
 
-#if defined(__linux__) && defined(__WXGTK3__)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(__WXGTK3__)
 #define wxLinux_gtk3 true
 #else
 #define wxLinux_gtk3 false
@@ -508,7 +508,7 @@ void PageWelcome::set_run_reason(ConfigW
     const bool data_empty = run_reason == ConfigWizard::RR_DATA_EMPTY;
     welcome_text->Show(data_empty);
     cbox_reset->Show(!data_empty);
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     if (!DesktopIntegrationDialog::is_integrated())
         cbox_integrate->Show(true);
     else
@@ -2595,7 +2595,7 @@ bool ConfigWizard::priv::apply_config(Ap
         if ((check_unsaved_preset_changes = install_bundles.size() > 0))
             header = _L_PLURAL("A new vendor was installed and one of its printers will be activated", "New vendors were installed and one of theirs printers will be activated", install_bundles.size());
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // Desktop integration on Linux
     if (page_welcome->integrate_desktop()) 
         DesktopIntegrationDialog::perform_desktop_integration();
