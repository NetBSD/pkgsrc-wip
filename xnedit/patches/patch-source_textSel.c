$NetBSD$

Enable codepath for Apple operating systems unconditionally.

Otherwise inserting the X11 primary selection does not work in some cases
(e.g. with selections from FLTK widgets on NetBSD).

--- source/textSel.c.orig	2022-01-09 12:28:40.000000000 +0000
+++ source/textSel.c
@@ -251,7 +251,9 @@ void InsertPrimarySelection(Widget w, Ti
     
     selectionTime = time;
     
-#ifdef __APPLE__
+
+/* #ifdef __APPLE__ */
+#if 1
     XtGetSelectionValue(w, XA_PRIMARY, targets[1], getSelectionCB, sel, time);
     XtGetSelectionValue(w, XA_PRIMARY, targets[0], getSelectionCB, sel, time);
 #else
