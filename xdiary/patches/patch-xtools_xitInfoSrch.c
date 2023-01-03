$NetBSD$

--- xtools/xitInfoSrch.c.orig	1997-05-04 22:25:10.000000000 +0000
+++ xtools/xitInfoSrch.c
@@ -406,7 +406,7 @@ static Widget
     gotoBu[ index ] = xitCreatePushButton( gotoRc, &goto_def[ index ] );
 
     XtAddCallback( gotoBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) gotoCB, (XtPointer) index );
+                   (XtCallbackProc) gotoCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -663,7 +663,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Next? */
     case 0:
