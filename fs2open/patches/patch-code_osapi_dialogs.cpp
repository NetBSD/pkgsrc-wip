$NetBSD$

Provide fallback error messages to stderr.

--- code/osapi/dialogs.cpp.orig	2019-12-16 14:07:42.626176361 +0000
+++ code/osapi/dialogs.cpp
@@ -11,6 +11,7 @@
 
 #include <string>
 #include <algorithm>
+#include <iostream>
 
 extern "C" {
 #include <lauxlib.h>
@@ -251,6 +252,9 @@ namespace os
 			if (SDL_ShowMessageBox(&boxData, &buttonId) < 0)
 			{
 				// Call failed
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
 				buttonId = 1; // No action
 			}
 
@@ -335,6 +339,9 @@ namespace os
 			if (SDL_ShowMessageBox(&boxData, &buttonId) < 0)
 			{
 				// Call failed
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
 				abort();
 			}
 
@@ -403,6 +410,9 @@ namespace os
 			if (SDL_ShowMessageBox(&boxData, &buttonId) < 0)
 			{
 				// Call failed
+				std::cerr << "(SDL_ShowMessageBox failed: " << SDL_GetError() << ")" << std::endl;
+				std::cerr << boxData.message << std::endl;
+				std::cerr.flush();
 				abort();
 			}
 
