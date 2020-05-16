$NetBSD$

Rewind to the start of the password database.

--- src/greeter/UserModel.cpp.orig	2019-03-31 07:59:59.000000000 +0000
+++ src/greeter/UserModel.cpp
@@ -60,6 +60,8 @@ namespace SDDM {
                 QFile::exists(themeDefaultFace) ? themeDefaultFace : defaultFace);
 
         struct passwd *current_pw;
+
+        setpwent();
         while ((current_pw = getpwent()) != nullptr) {
 
             // skip entries with uids smaller than minimum uid
