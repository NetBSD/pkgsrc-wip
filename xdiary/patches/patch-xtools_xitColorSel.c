$NetBSD$

--- xtools/xitColorSel.c.orig	1997-05-04 13:13:45.000000000 +0000
+++ xtools/xitColorSel.c
@@ -302,7 +302,7 @@ Widget
     XtManageChild( menuPb );
 
     XtAddCallback( menuPb, XmNactivateCallback, 
-                   (XtCallbackProc) menuSelectCB, (XtPointer) index );
+                   (XtCallbackProc) menuSelectCB, (XtPointer)(intptr_t)index );
 
     /* The default color is the first color. */
     if( index == 0 ) {
