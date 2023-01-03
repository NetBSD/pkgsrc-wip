$NetBSD$

--- dtools/xtmSchedAct.c.orig	1997-05-04 21:16:55.000000000 +0000
+++ dtools/xtmSchedAct.c
@@ -1967,7 +1967,7 @@ static Widget
 
     if( XmIsPushButton( menuPopupBu[ index ] ) )
       XtAddCallback( menuPopupBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) entryPuMenuCB, (XtPointer) index );
+                     (XtCallbackProc) entryPuMenuCB, (XtPointer)(intptr_t)index );
   }
 
   XtManageChildren( menuPopupBu, XtNumber( menuPopupBu ) );
@@ -2106,7 +2106,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Edit the entry. */
     case 0:
