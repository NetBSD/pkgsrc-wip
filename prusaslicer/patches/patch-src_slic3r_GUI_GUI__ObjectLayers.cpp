$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_ObjectLayers.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/GUI_ObjectLayers.cpp
@@ -344,7 +344,7 @@ LayerRangeEditor::LayerRangeEditor( Obje
         m_enter_pressed     = true;
         // Workaround! Under Linux we have to use CallAfter() to avoid crash after pressing ENTER key
         // see #7531, #8055, #8408
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         wxTheApp->CallAfter([this, edit_fn]() {
 #endif
             // If LayersList wasn't updated/recreated, we can call wxEVT_KILL_FOCUS.Skip()
@@ -359,7 +359,7 @@ LayerRangeEditor::LayerRangeEditor( Obje
                 SetValue(m_valid_value);
                 m_call_kill_focus = true;
             }
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         });
 #endif 
     }, this->GetId());
