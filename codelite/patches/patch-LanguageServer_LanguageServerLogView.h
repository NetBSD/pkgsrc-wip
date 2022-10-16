$NetBSD$

Reorder <wx/menu.h> to fix build in NetBSD.

--- LanguageServer/LanguageServerLogView.h	2022-05-02 22:26:31.620093956 +0300
+++ LanguageServer/LanguageServerLogView.h
@@ -1,5 +1,6 @@
 #ifndef LANGUAGESERVERLOGVIEW_H
 #define LANGUAGESERVERLOGVIEW_H
+#include <wx/menu.h>
 #include "UI.h"
 
 class LanguageServerLogView : public LanguageServerLogViewBase
