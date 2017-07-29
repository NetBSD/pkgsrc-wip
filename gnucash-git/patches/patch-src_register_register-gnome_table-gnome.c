$NetBSD$

Use proper glib2 header path.

--- src/register/register-gnome/table-gnome.c.orig	2017-07-27 09:52:15.000000000 +0000
+++ src/register/register-gnome/table-gnome.c
@@ -42,7 +42,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "gnucash-sheet.h"
 #include "gnucash-sheetP.h"
