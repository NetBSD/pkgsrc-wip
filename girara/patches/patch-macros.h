$NetBSD: patch-macros.h,v 1.2 2015/04/14 18:09:40 leot1990 Exp $

pragma GCC diagnostic only acts on some lines.
See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52116

--- girara/macros.h.orig	2014-06-24 20:27:39.000000000 +0000
+++ girara/macros.h
@@ -51,7 +51,7 @@
 #endif
 
 #ifndef GIRARA_DO_PRAGMA
-# if defined(__GNUC__) || defined(__clang__)
+# if defined(__clang__)
 #  define GIRARA_DO_PRAGMA(x) _Pragma(#x)
 # else
 #  define GIRARA_DO_PRAGMA(x)
