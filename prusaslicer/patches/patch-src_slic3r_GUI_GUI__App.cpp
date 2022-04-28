$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_App.cpp.orig	2022-04-22 11:01:19.000000000 +0000
+++ src/slic3r/GUI/GUI_App.cpp
@@ -374,7 +374,7 @@ private:
 };
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 bool static check_old_linux_datadir(const wxString& app_name) {
     // If we are on Linux and the datadir does not exist yet, look into the old
     // location where the datadir was before version 2.3. If we find it there,
@@ -839,7 +839,7 @@ wxGLContext* GUI_App::init_glcontext(wxG
 
 bool GUI_App::init_opengl()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     bool status = m_opengl_mgr.init_gl();
     m_opengl_initialized = true;
     return status;
@@ -880,7 +880,7 @@ void GUI_App::init_app_config()
 	// Mac : "~/Library/Application Support/Slic3r"
 
     if (data_dir().empty()) {
-        #ifndef __linux__
+        #if !defined(__linux__) && !defined(__NetBSD__)
             set_data_dir(wxStandardPaths::Get().GetUserDataDir().ToUTF8().data());
         #else
             // Since version 2.3, config dir on Linux is in ${XDG_CONFIG_HOME}.
@@ -1070,7 +1070,7 @@ bool GUI_App::on_init_inner()
     wxCHECK_MSG(wxDirExists(resources_dir), false,
         wxString::Format("Resources path does not exist or is not a directory: %s", resources_dir));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     if (! check_old_linux_datadir(GetAppName())) {
         std::cerr << "Quitting, user chose to move their data to new location." << std::endl;
         return false;
@@ -1171,7 +1171,7 @@ bool GUI_App::on_init_inner()
         if (!default_splashscreen_pos)
             // revert "restore_win_position" value if application wasn't crashed
             get_app_config()->set("restore_win_position", "1");
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
         wxYield();
 #endif
         scrn->SetText(_L("Loading configuration")+ dots);
@@ -1311,7 +1311,7 @@ bool GUI_App::on_init_inner()
 
         // An ugly solution to GH #5537 in which GUI_App::init_opengl (normally called from events wxEVT_PAINT
         // and wxEVT_SET_FOCUS before GUI_App::post_init is called) wasn't called before GUI_App::post_init and OpenGL wasn't initialized.
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         if (! m_post_initialized && m_opengl_initialized) {
 #else
         if (! m_post_initialized) {
@@ -1897,7 +1897,7 @@ bool GUI_App::switch_language()
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 static const wxLanguageInfo* linux_get_existing_locale_language(const wxLanguageInfo* language,
                                                                 const wxLanguageInfo* system_language)
 {
@@ -2086,7 +2086,7 @@ bool GUI_App::load_language(wxString lan
 				m_language_info_best = wxLocale::FindLanguageInfo(best_language);
 	        	BOOST_LOG_TRIVIAL(trace) << boost::format("Best translation language detected (may be different from user locales): %1%") % m_language_info_best->CanonicalName.ToUTF8().data();
 			}
-            #ifdef __linux__
+            #if defined(__linux__) || defined(__NetBSD__)
             wxString lc_all;
             if (wxGetEnv("LC_ALL", &lc_all) && ! lc_all.IsEmpty()) {
                 // Best language returned by wxWidgets on Linux apparently does not respect LC_ALL.
@@ -2139,7 +2139,7 @@ bool GUI_App::load_language(wxString lan
     } else if (m_language_info_system != nullptr && language_info->CanonicalName.BeforeFirst('_') == m_language_info_system->CanonicalName.BeforeFirst('_'))
         language_info = m_language_info_system;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // If we can't find this locale , try to use different one for the language
     // instead of just reporting that it is impossible to switch.
     if (! wxLocale::IsAvailable(language_info->Language)) {
@@ -2239,7 +2239,7 @@ void GUI_App::add_config_menu(wxMenuBar 
         local_menu->Append(config_id_base + ConfigMenuSnapshots, _L("&Configuration Snapshots") + dots, _L("Inspect / activate configuration snapshots"));
         local_menu->Append(config_id_base + ConfigMenuTakeSnapshot, _L("Take Configuration &Snapshot"), _L("Capture a configuration snapshot"));
         local_menu->Append(config_id_base + ConfigMenuUpdate, _L("Check for Configuration Updates"), _L("Check for configuration updates"));
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
         //if (DesktopIntegrationDialog::integration_possible())
         local_menu->Append(config_id_base + ConfigMenuDesktopIntegration, _L("Desktop Integration"), _L("Desktop Integration"));    
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)        
@@ -2283,7 +2283,7 @@ void GUI_App::add_config_menu(wxMenuBar 
 		case ConfigMenuUpdate:
 			check_updates(true);
 			break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         case ConfigMenuDesktopIntegration:
             show_desktop_integration_dialog();
             break;
@@ -2905,7 +2905,7 @@ bool GUI_App::run_wizard(ConfigWizard::R
 
 void GUI_App::show_desktop_integration_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     //wxCHECK_MSG(mainframe != nullptr, false, "Internal error: Main frame not created / null");
     DesktopIntegrationDialog dialog(mainframe);
     dialog.ShowModal();
