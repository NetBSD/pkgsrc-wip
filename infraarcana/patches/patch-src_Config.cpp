$NetBSD: patch-src_Config.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store config in home directory

--- src/Config.cpp.orig	2015-02-18 19:24:13.000000000 +0000
+++ src/Config.cpp
@@ -2,6 +2,7 @@
 
 #include "Init.h"
 
+#include <cstdlib>
 #include <fstream>
 #include <SDL_image.h>
 
@@ -472,7 +473,16 @@ void draw(const MenuBrowser* const brows
 void readFile(vector<string>& lines)
 {
     ifstream file;
-    file.open("data/config");
+
+    char *home = getenv("HOME");
+    string config = "data/config";
+    if (home != NULL)
+    {
+        config = home;
+        config += "/.ia_config";
+    }
+
+    file.open(config);
     if (file.is_open())
     {
         string line;
@@ -563,8 +573,16 @@ void setAllVariablesFromLines(vector<str
 void writeLinesToFile(vector<string>& lines)
 {
     ofstream file;
-    file.open("data/config", ios::trunc);
 
+    char *home = getenv("HOME");
+    string config = "data/config";
+    if (home != NULL)
+    {
+        config = home;
+        config += "/.ia_config";
+    }
+
+    file.open(config, ios::trunc);
     for (size_t i = 0; i < lines.size(); ++i)
     {
         file << lines[i];
