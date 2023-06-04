$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ConfigWizard.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/ConfigWizard.cpp
@@ -60,7 +60,7 @@
 #include "slic3r/GUI/I18N.hpp"
 #include "slic3r/Config/Version.hpp"
 
-#if defined(__linux__) && defined(__WXGTK3__)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(__WXGTK3__)
 #define wxLinux_gtk3 true
 #else
 #define wxLinux_gtk3 false
@@ -583,7 +583,7 @@ void PageWelcome::set_run_reason(ConfigW
     const bool data_empty = run_reason == ConfigWizard::RR_DATA_EMPTY;
     welcome_text->Show(data_empty);
     cbox_reset->Show(!data_empty);
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     if (!DesktopIntegrationDialog::is_integrated())
         cbox_integrate->Show(true);
     else
@@ -1474,7 +1474,7 @@ PageDownloader::PageDownloader(ConfigWiz
         " The model will be downloaded into folder you choose bellow."
     ), SLIC3R_APP_NAME));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     append_text(wxString::Format(_L(
         "On Linux systems the process of registration also creates desktop integration files for this version of application."
     )));
@@ -3106,7 +3106,7 @@ bool ConfigWizard::priv::apply_config(Ap
         if ((check_unsaved_preset_changes = install_bundles.size() > 0))
             header = _L_PLURAL("A new vendor was installed and one of its printers will be activated", "New vendors were installed and one of theirs printers will be activated", install_bundles.size());
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // Desktop integration on Linux
     BOOST_LOG_TRIVIAL(debug) << "ConfigWizard::priv::apply_config integrate_desktop" << page_welcome->integrate_desktop()  << " perform_registration_linux " << page_downloader->m_downloader->get_perform_registration_linux();
     if (page_welcome->integrate_desktop())
