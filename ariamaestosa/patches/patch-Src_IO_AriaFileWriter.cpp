$NetBSD: patch-Src_IO_AriaFileWriter.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/IO/AriaFileWriter.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/IO/AriaFileWriter.cpp
@@ -22,7 +22,7 @@
 #include <wx/string.h>
 #include <wx/wfstream.h>
 #include <wx/msgdlg.h>
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 namespace AriaMaestosa
 {
