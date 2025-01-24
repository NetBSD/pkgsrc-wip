$NetBSD$

2024-01-24: Patch modified for FLTK 1.4

--- GUI/OutputGUI.C.orig	2001-04-19 20:48:10.000000000 +0000
+++ GUI/OutputGUI.C
@@ -18,7 +18,7 @@
 
 #include "OutputGUI.h"
 
-#include <FL/fl_file_chooser.h>
+#include <FL/Fl_File_Chooser.H>
 
 OutputGUI::OutputGUI(Output *o)
 {
@@ -26,7 +26,7 @@ OutputGUI::OutputGUI(Output *o)
 	if (!m_out) cerr<<"WARNING: Output not correctly set up"<<endl;
 }
 		
-void OutputGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void OutputGUI::CreateGUI(int xoff, int yoff, char *name)
 {
 	 Fl_Group* o = GUIMixGroup = new Fl_Group(xoff, yoff, 85, 110, name);
       o->type(1);
