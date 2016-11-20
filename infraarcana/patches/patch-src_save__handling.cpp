$NetBSD: patch-src_SaveHandling.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store saves in home directory

--- src/save_handling.cpp.orig	2016-07-02 15:42:10.000000000 +0000
+++ src/save_handling.cpp
@@ -104,8 +104,16 @@ void load_modules()
 void write_file()
 {
     std::ofstream file;
+    char *home = getenv("HOME");
+    std::string save = "data/save";
 
-    file.open("data/save", std::ios::trunc);
+    if (home != NULL)
+    {
+        save = home;
+        save += "/.ia_save";
+    }
+
+    file.open(save, std::ios::trunc);
 
     if (file.is_open())
     {
@@ -125,7 +133,16 @@ void write_file()
 
 void read_file()
 {
-    std::ifstream file("data/save");
+    char *home = getenv("HOME");
+    std::string save = "data/save";
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
