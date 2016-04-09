$NetBSD$

Fix clang build.

--- src/lsof.cpp.orig	2015-09-25 11:36:19.000000000 +0000
+++ src/lsof.cpp
@@ -140,7 +140,7 @@ namespace
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = (std::ostringstream() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
