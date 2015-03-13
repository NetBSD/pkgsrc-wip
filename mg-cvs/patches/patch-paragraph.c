$NetBSD: patch-paragraph.c,v 1.1 2015/03/13 22:08:53 krytarowski Exp $

Include limits.h for INT_{MIN,MAX}

--- paragraph.c.orig	2011-01-02 22:57:56.000000000 +0000
+++ paragraph.c
@@ -9,6 +9,8 @@
 
 #include "def.h"
 
+#include <limits.h>
+
 static int	fillcol = 70;
 
 #define MAXWORD 256
