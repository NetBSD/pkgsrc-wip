$NetBSD$

2024-01-24: Patch modified for FLTK 1.4

--- SpiralLoops.C.orig	2001-04-19 20:48:11.000000000 +0000
+++ SpiralLoops.C
@@ -20,7 +20,7 @@
 
 #include <FL/Fl.H>
 #include <FL/Enumerations.H>
-#include <FL/fl_file_chooser.h>
+#include <FL/Fl_File_Chooser.H>
 #include <fstream>
 #include <strstream>
 #include <string>
@@ -48,6 +48,7 @@ m_PluginOpen(false),
 m_PluginLinked(false),
 m_PluginPaused(false),
 m_PluginWindow(NULL),
+m_PluginBuffer(NULL),
 m_DelayGUI(&m_Delay),
 m_ReverbGUI(&m_Reverb),
 m_Out(2),
