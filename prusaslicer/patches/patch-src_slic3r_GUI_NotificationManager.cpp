$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/NotificationManager.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/NotificationManager.cpp
@@ -337,8 +337,11 @@ void NotificationManager::PopNotificatio
 	if (is_finished())
 		return;
 
+	// stix
+	// wxGetApp().imgui()->new_frame();
 	count_spaces();
 	count_lines();
+	// ImGui::EndFrame();
 
 	if (m_lines_count == 3)
 		m_multiline = true;
