$NetBSD$

Don't crash if XDG_CURRENT_DESKTOP is not set.

--- guikit/gtk/main.cpp.orig	2022-06-27 19:02:54.000000000 +0000
+++ guikit/gtk/main.cpp
@@ -78,6 +78,9 @@ auto pApplication::fetchDesktopSession()
 
     const char* currentDesktop = getenv("XDG_CURRENT_DESKTOP");
 
+    if (currentDesktop == NULL)
+	return;
+
     if (String::findString(currentDesktop, "Cinnamon"))
         desktopSession = DesktopSession::Cinnamon;
     else if (String::findString(currentDesktop, "GNOME"))
