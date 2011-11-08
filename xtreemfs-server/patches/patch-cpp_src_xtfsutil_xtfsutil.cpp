$NetBSD: patch-cpp_src_xtfsutil_xtfsutil.cpp,v 1.1.1.1 2011/11/08 01:42:14 tnn2 Exp $

--- cpp/src/xtfsutil/xtfsutil.cpp.orig	2011-11-03 10:51:07.000000000 +0000
+++ cpp/src/xtfsutil/xtfsutil.cpp
@@ -706,7 +706,7 @@ bool SetRemoveACL(const string& full_pat
   } else {
     return false;
   }
-#ifdef __linux
+#if defined(__linux) || defined(__NetBSD__)
   int result = setxattr(full_path.c_str(),
                         "xtreemfs.acl",
                         contents.c_str(),
@@ -875,7 +875,7 @@ int main(int argc, char **argv) {
   
   // get xtreemfs.url xattr.
   char xtfs_url[2048];
-#ifdef __linux
+#if defined(__linux) || defined(__NetBSD__)
   int length = getxattr(real_path_cstr, "xtreemfs.url", xtfs_url, 2048);
 #elif __APPLE__
   int length = getxattr(real_path_cstr, "xtreemfs.url", xtfs_url, 2048, 0, 0);
