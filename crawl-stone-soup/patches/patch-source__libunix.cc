$NetBSD: patch-source__libunix.cc,v 1.1 2013/07/13 12:59:23 genolopolis Exp $

--- libunix.cc-orig	2013-07-13 11:50:38.000000000 +0000
+++ libunix.cc
@@ -21,7 +21,6 @@
 #include <unistd.h>
 #include <stdarg.h>
 #include <ctype.h>
-#include <term.h>
 #define _LIBUNIX_IMPLEMENTATION
 #include "libunix.h"
 #include "defines.h"
