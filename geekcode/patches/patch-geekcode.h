$NetBSD: patch-geekcode.h,v 1.1 2014/06/05 23:35:52 yrmt Exp $

Needs stdlib.h

--- geekcode.h.orig	2003-06-30 14:47:40.000000000 +0000
+++ geekcode.h
@@ -22,6 +22,7 @@
 #ifndef __INCLUDED_GEEKCODE_H__
 #define __INCLUDED_GEEKCODE_H__
 
+#include <stdlib.h>
 
 #define VERSION "1.7.3" /* Added in v1.2 */
 
