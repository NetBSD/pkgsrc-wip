$NetBSD: patch-include_kiway.h,v 1.2 2016/09/08 09:32:28 bouyer Exp $

Add NetBSD support.

--- include/kiway.h.orig	2018-07-13 19:53:52.000000000 +0000
+++ include/kiway.h
@@ -116,7 +116,7 @@ as such!  As such, it is OK to use UTF8 
 #define KIFACE_INSTANCE_NAME_AND_VERSION   "KIFACE_1"
 
 #ifndef SWIG
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
  #define LIB_ENV_VAR    wxT( "LD_LIBRARY_PATH" )
 #elif defined(__WXMAC__)
  #define LIB_ENV_VAR    wxT( "DYLD_LIBRARY_PATH" )
