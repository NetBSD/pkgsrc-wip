$NetBSD$

Unsure why the class override of the pointer operator isn't working

--- src/udir.cc.orig	2024-03-25 19:03:14.000000000 +0000
+++ src/udir.cc
@@ -22,6 +22,7 @@ public:
     operator DIR*() const { return ptr; }
     operator bool() const { return ptr != nullptr; }
 
+    DIR* dir() const { return ptr; }
     char* name() const { return de->d_name; }
     int length() const { return int(strlen(name())); }
     int size() const { return 1 + length(); }
@@ -152,7 +153,7 @@ void cdir::rewind() {
 }
 
 int cdir::descriptor() const {
-    return dirp ? dirfd(*dirp) : -1;
+    return dirp ? dirfd(dirp->dir()) : -1;
 }
 
 adir::adir(const char* path)
@@ -270,7 +271,7 @@ bool udir::nextFile() {
 }
 
 int udir::descriptor() const {
-    return dirp ? dirfd(*dirp) : -1;
+    return dirp ? dirfd(dirp->dir()) : -1;
 }
 
 sdir::sdir(upath path)
