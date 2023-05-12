$NetBSD$

Workaround for errors like "call of overloaded 'set(x, y)' is ambiguous".

--- DiffWindow.cxx.orig	2006-11-13 18:54:02.000000000 +0000
+++ DiffWindow.cxx
@@ -1126,13 +1126,13 @@ void
 DiffWindow::save_prefs()
 {
   // Save the window prefs for the next run...
-  prefs_.set("color", color());
-  prefs_.set("selection_color", selection_color());
-  prefs_.set("showlinenum", showlinenum());
-  prefs_.set("tabwidth", tabwidth());
-  prefs_.set("textcolor", textcolor());
-  prefs_.set("textsize", textsize());
-  prefs_.set("ignoreblanks", ignoreblanks());
+  prefs_.set("color", (int)color());
+  prefs_.set("selection_color", (int)selection_color());
+  prefs_.set("showlinenum", (int)showlinenum());
+  prefs_.set("tabwidth", (int)tabwidth());
+  prefs_.set("textcolor", (int)textcolor());
+  prefs_.set("textsize", (int)textsize());
+  prefs_.set("ignoreblanks", (int)ignoreblanks());
 }
 
 
