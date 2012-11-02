$NetBSD: patch-Src_Midi_Note.cpp,v 1.1 2012/11/02 20:39:32 othyro Exp $

Use system irrXML instead of bundled.

--- Src/Midi/Note.cpp.orig	2012-10-16 23:38:51.000000000 +0000
+++ Src/Midi/Note.cpp
@@ -23,7 +23,7 @@
 #include "Utils.h"
 #include "UnitTest.h"
 
-#include "irrXML/irrXML.h"
+#include <irrXML/irrXML.h>
 
 #include <iostream>
 
