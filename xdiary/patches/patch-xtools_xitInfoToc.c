$NetBSD$

--- xtools/xitInfoToc.c.orig	1997-05-04 13:15:28.000000000 +0000
+++ xtools/xitInfoToc.c
@@ -355,7 +355,7 @@ static Widget
     gotoBu[ index ] = xitCreatePushButton( gotoRc, &goto_def[ index ] );
 
     XtAddCallback( gotoBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) gotoCB, (XtPointer) index );
+                   (XtCallbackProc) gotoCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -702,7 +702,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Next? */
     case 0:
