$NetBSD: patch-src_utility.cpp,v 1.1 2012/11/29 14:22:55 ryo-on Exp $

* Fix recent gcc build from Arch Linux

--- src/utility.cpp.orig	2006-02-14 04:57:01.000000000 +0000
+++ src/utility.cpp
@@ -4,6 +4,7 @@
 
 
 #include <ctype.h>
+#include <cstdio>
 #include "utility.h"
 #include "internal.h"
 
