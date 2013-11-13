$NetBSD: patch-flower_include_std-vector.hh,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- flower/include/std-vector.hh.orig	2013-11-12 11:12:50.000000000 +0000
+++ flower/include/std-vector.hh
@@ -20,6 +20,8 @@
 #ifndef STD_VECTOR_HH
 #define STD_VECTOR_HH
 
+#include "config.hh"
+
 #if 0
 
 /*
