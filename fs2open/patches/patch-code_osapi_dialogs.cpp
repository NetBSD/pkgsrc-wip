$NetBSD$

Provide fallback error messages to stderr.

--- code/osapi/dialogs.cpp.orig	2021-01-27 17:07:03.000000000 +0000
+++ code/osapi/dialogs.cpp
@@ -11,6 +11,7 @@
 
 #include <string>
 #include <algorithm>
+#include <iostream>
 
 extern "C" {
 #include <lauxlib.h>
@@ -248,6 +249,9 @@ namespace os
 			if (SDL_ShowMessageBox(&boxData, &buttonId) < 0)
 			{
 				// Call failed
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
 				buttonId = 1; // No action
 			}
 
@@ -332,6 +336,12 @@ namespace os
 			if (SDL_ShowMessageBox(&boxData, &buttonId) < 0)
 			{
 				// Call failed
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
 				abort();
 			}
 
