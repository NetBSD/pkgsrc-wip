$NetBSD$

--- vm/src/any/runtime/uncommonBranch.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/runtime/uncommonBranch.cpp
@@ -124,7 +124,8 @@
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
    || TARGET_OS_FAMILY == MACOS_FAMILY \
    || TARGET_OS_VERSION == MACOSX_VERSION \
-   || TARGET_OS_VERSION == LINUX_VERSION
+   || TARGET_OS_VERSION == LINUX_VERSION \
+   || TARGET_OS_VERSION == NETBSD_VERSION
   void uncommonBranch_init() { }
 # elif  TARGET_OS_VERSION == SUNOS_VERSION
   extern "C" {
