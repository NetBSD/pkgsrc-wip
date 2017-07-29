$NetBSD$

Use proper glib2 header path.

--- src/register/register-gnome/gnucash-cursor.h.orig	2017-07-27 09:52:15.000000000 +0000
+++ src/register/register-gnome/gnucash-cursor.h
@@ -21,7 +21,7 @@
 #ifndef GNUCASH_CURSOR_H
 #define GNUCASH_CURSOR_H
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 #include "gnucash-sheet.h"
 
 /** @ingroup Register
