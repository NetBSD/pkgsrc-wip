$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ConfigWizard_private.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/ConfigWizard_private.hpp
@@ -619,7 +619,7 @@ struct ConfigWizard::priv
     bool apply_config(AppConfig *app_config, PresetBundle *preset_bundle, const PresetUpdater *updater, bool& apply_keeped_changes);
     // #ys_FIXME_alise
     void update_presets_in_config(const std::string& section, const std::string& alias_key, bool add);
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     void perform_desktop_integration() const;
 #endif
     bool check_fff_selected();        // Used to decide whether to display Filaments page
