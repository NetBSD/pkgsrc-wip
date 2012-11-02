$NetBSD: patch-Src_GUI_GraphicalTrack.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/GUI/GraphicalTrack.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/GUI/GraphicalTrack.cpp
@@ -51,7 +51,7 @@
 #include "Renderers/ImageBase.h"
 #include "Renderers/RenderAPI.h"
 
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 using namespace AriaMaestosa;
 
