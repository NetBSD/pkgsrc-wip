$NetBSD$

Fix clang build.

--- src/lsof.cpp.orig	2016-04-05 16:12:54.000000000 +0000
+++ src/lsof.cpp
@@ -137,7 +137,7 @@ namespace
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = (std::ostringstream() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
