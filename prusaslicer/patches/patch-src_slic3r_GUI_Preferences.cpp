$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/Preferences.cpp.orig	2024-04-05 09:25:31.000000000 +0000
+++ src/slic3r/GUI/Preferences.cpp
@@ -28,7 +28,7 @@
 #ifdef WIN32
 #include <wx/msw/registry.h>
 #endif // WIN32
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
 #include "DesktopIntegrationDialog.hpp"
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
 
@@ -262,7 +262,7 @@ void PreferencesDialog::build()
 	tabs = new Notebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP | wxTAB_TRAVERSAL | wxNB_NOPAGETHEME | wxNB_DEFAULT);
 #else
     tabs = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP | wxTAB_TRAVERSAL  |wxNB_NOPAGETHEME | wxNB_DEFAULT );
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 	tabs->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, [this](wxBookCtrlEvent& e) {
 		e.Skip();
 		CallAfter([this]() { tabs->GetCurrentPage()->Layout(); });
@@ -758,7 +758,7 @@ void PreferencesDialog::accept(wxEvent&)
 			downloader->allow(it->second == "1");
 		if (!downloader->on_finish())
 			return;
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
 		if( downloader->get_perform_registration_linux()) 
 			DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
@@ -1141,7 +1141,7 @@ void PreferencesDialog::create_settings_
 		font_example->SetFont(font);
 		m_values[opt_key] = format("%1%", val);
 		stb_sizer->Layout();
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 		CallAfter([this]() { refresh_og(m_optgroup_other); });
 #else
 		refresh_og(m_optgroup_other);
