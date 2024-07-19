$NetBSD$

Add header for isblank().

--- CPP/Common/CommandLineParser.cpp.orig	2023-06-18 13:11:43.000000000 +0000
+++ CPP/Common/CommandLineParser.cpp
@@ -4,6 +4,8 @@
 
 #include "CommandLineParser.h"
 
+#include <ctype.h>
+
 namespace NCommandLineParser {
 
 static const wchar_t * _SplitCommandLine(const wchar_t* s, UString &dest)
