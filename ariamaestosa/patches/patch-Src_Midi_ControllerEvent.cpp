$NetBSD: patch-Src_Midi_ControllerEvent.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/Midi/ControllerEvent.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/Midi/ControllerEvent.cpp
@@ -18,7 +18,7 @@
 #include "Midi/Sequence.h"
 #include "Midi/Track.h"
 
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 using namespace AriaMaestosa;
 
@@ -167,4 +167,4 @@ bool TextEvent::readFromFile(irr::io::Ir
     return true;
 }
 
-// ----------------------------------------------------------------------------------------------------------
\ No newline at end of file
+// ----------------------------------------------------------------------------------------------------------
