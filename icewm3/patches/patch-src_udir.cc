$NetBSD$

--- src/udir.cc.orig	2024-05-11 00:36:47.708916561 +0000
+++ src/udir.cc
@@ -152,7 +152,7 @@ void cdir::rewind() {
 }
 
 int cdir::descriptor() const {
-    return dirp ? dirfd(*dirp) : -1;
+    return dirp ? 1 : -1;
 }
 
 adir::adir(const char* path)
@@ -270,7 +270,7 @@ bool udir::nextFile() {
 }
 
 int udir::descriptor() const {
-    return dirp ? dirfd(*dirp) : -1;
+    return dirp ? 1 : -1;
 }
 
 sdir::sdir(upath path)
