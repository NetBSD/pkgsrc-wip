$NetBSD: patch-src_Config.cpp,v 1.1 2015/08/19 19:42:29 yhardy Exp $

Store config in home directory

--- src/config.cpp.orig	2016-07-02 15:42:10.000000000 +0000
+++ src/config.cpp
@@ -512,7 +512,16 @@ void draw(const Menu_browser* const brow
 void read_file(std::vector<std::string>& lines)
 {
     std::ifstream file;
-    file.open("data/config");
+    char *home = getenv("HOME");
+    std::string config = "data/config";
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
@@ -605,7 +614,16 @@ void set_variables_from_lines(std::vecto
 void write_lines_to_file(std::vector<std::string>& lines)
 {
     std::ofstream file;
-    file.open("data/config", std::ios::trunc);
+    char *home = getenv("HOME");
+    std::string config = "data/config";
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
