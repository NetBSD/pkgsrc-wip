$NetBSD: patch-Src_GUI_GraphicalSequence.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/GUI/GraphicalSequence.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/GUI/GraphicalSequence.cpp
@@ -22,7 +22,7 @@
 #include "Midi/Sequence.h"
 #include "PreferencesData.h"
 
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 using namespace AriaMaestosa;
 
