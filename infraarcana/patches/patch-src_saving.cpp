$NetBSD: patch-src_SaveHandling.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store saves in home directory

--- src/saving.cpp.orig	2017-07-20 14:19:08.000000000 +0000
+++ src/saving.cpp
@@ -103,8 +103,16 @@ void load_modules()
 void write_file()
 {
     std::ofstream file;
+    char *home = getenv("HOME");
+    std::string save = "res/data/save";
 
-    file.open("res/data/save", std::ios::trunc);
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    file.open(save, std::ios::trunc);
 
     if (file.is_open())
     {
@@ -124,7 +132,16 @@ void write_file()
 
 void read_file()
 {
-    std::ifstream file("res/data/save");
+    char *home = getenv("HOME");
+    std::string save = "res/data/save";
+
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    std::ifstream file(save);
 
     if (file.is_open())
     {
@@ -208,7 +225,17 @@ void load_game()
 
 bool is_save_available()
 {
-    std::ifstream file("res/data/save");
+    std::ifstream file;
+    char *home = getenv("HOME");
+    std::string save = "res/data/save";
+
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    file.open(save);
 
     if (file.good())
     {
