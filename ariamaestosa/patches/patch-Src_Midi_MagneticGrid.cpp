$NetBSD: patch-Src_Midi_MagneticGrid.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/Midi/MagneticGrid.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/Midi/MagneticGrid.cpp
@@ -19,7 +19,7 @@
 #include "IO/IOUtils.h"
 
 #include "AriaCore.h"
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 using namespace AriaMaestosa;
 
