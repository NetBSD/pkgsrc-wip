$NetBSD: patch-src_SaveHandling.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store saves in home directory

--- src/SaveHandling.cpp.orig	2015-02-18 19:24:13.000000000 +0000
+++ src/SaveHandling.cpp
@@ -1,5 +1,6 @@
 #include "SaveHandling.h"
 
+#include <cstdlib>
 #include <fstream>
 #include <iostream>
 
@@ -73,7 +74,16 @@ void setupGameFromLines(vector<string>& 
 void writeFile(const vector<string>& lines)
 {
     ofstream file;
-    file.open("data/save", ios::trunc);
+
+    char *home = getenv("HOME");
+    string save = "data/save";
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    file.open(save, ios::trunc);
 
     if (file.is_open())
     {
@@ -91,7 +101,16 @@ void readFile(vector<string>& lines)
     lines.clear();
 
     string curLine;
-    ifstream file("data/save");
+
+    char *home = getenv("HOME");
+    string save = "data/save";
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    ifstream file(save);
     if (file.is_open())
     {
         while (getline(file, curLine)) {lines.push_back(curLine);}
