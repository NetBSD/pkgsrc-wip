$NetBSD$

Use new name of header for FLTK 1.4.

--- GUI/LoopGUI.C.orig	2001-04-19 20:48:10.000000000 +0000
+++ GUI/LoopGUI.C
@@ -21,7 +21,7 @@
 #include "Widgets/Fl_Loop.h"
 #include "LoopGUI.h"
 #include "../Loop.h"
-#include <FL/fl_file_chooser.h>
+#include <FL/Fl_File_Chooser.H>
 
 static const int EFFECT_ADDITION = 130;
 
