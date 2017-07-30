$NetBSD: patch-src_Config.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store config in home directory

--- src/config.cpp.orig	2017-07-20 14:19:08.000000000 +0000
+++ src/config.cpp
@@ -369,7 +369,16 @@ void player_sets_option(const MenuBrowse
 void read_file(std::vector<std::string>& lines)
 {
     std::ifstream file;
-    file.open("res/data/config");
+    char *home = getenv("HOME");
+    std::string config = "res/data/config";
+
+    if (home != NULL)
+    {
+        config = home;
+        config += "/.ia_config";
+    }
+
+    file.open(config);
 
     if (file.is_open())
     {
@@ -454,6 +463,16 @@ void write_lines_to_file(const std::vect
 {
     std::ofstream file;
     file.open("res/data/config", std::ios::trunc);
+    char *home = getenv("HOME");
+    std::string config = "res/data/config";
+
+    if (home != NULL)
+    {
+        config = home;
+        config += "/.ia_config";
+    }
+
+    file.open(config, std::ios::trunc);
 
     for (size_t i = 0; i < lines.size(); ++i)
     {
