$NetBSD: patch-Src_Midi_Sequence.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/Midi/Sequence.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/Midi/Sequence.cpp
@@ -43,7 +43,7 @@ const int CURRENT_FILE_VERSION = 4;
 #include <wx/intl.h>
 #include <wx/utils.h>
 #include <wx/msgdlg.h>
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 using namespace AriaMaestosa;
 
