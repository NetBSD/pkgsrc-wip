$NetBSD$

--- src/scintillaeditor.h.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/scintillaeditor.h
@@ -12,8 +12,10 @@
 #include "parsersettings.h"
 
 #include "memory.h"
+#ifndef Q_MOC_RUN
 #include <boost/property_tree/ptree.hpp>
 #include <boost/property_tree/json_parser.hpp>
+#endif
 
 class EditorColorScheme
 {
