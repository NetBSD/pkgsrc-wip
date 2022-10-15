$NetBSD$

--- Plugin/DiffSideBySidePanel.h.orig	2022-04-18 08:09:00.000000000 +0300
+++ Plugin/DiffSideBySidePanel.h
@@ -26,13 +26,15 @@
 #ifndef DIFFSIDEBYSIDEPANEL_H
 #define DIFFSIDEBYSIDEPANEL_H
 
+#include <wx/filename.h>
+
+#include "wxcrafter_plugin.h"
 #include "DiffConfig.h"
 #include "clDTL.h"
 #include "clPluginsFindBar.h"
 #include "wxcrafter_plugin.h"
 
 #include <vector>
-#include <wx/filename.h>
 
 class clToolBar;
 class WXDLLIMPEXP_SDK DiffSideBySidePanel : public DiffSideBySidePanelBase
