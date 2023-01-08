$NetBSD$

The call canonicalize_file_name(path) is equivalent to the call
realpath(name, NULL).

--- avidemux_core/ADM_core/src/ADM_folder_linux.cpp.orig	2022-09-17 13:59:17.000000000 +0000
+++ avidemux_core/ADM_core/src/ADM_folder_linux.cpp
@@ -39,7 +39,7 @@ static std::string ADM_i18nDir;
 static std::string canonize(const std::string &in)
 {
     std::string out;
-    char *simple2=canonicalize_file_name(in.c_str());
+    char *simple2=realpath(in.c_str(), NULL);
     if(simple2)
     {
         out=std::string(simple2);
