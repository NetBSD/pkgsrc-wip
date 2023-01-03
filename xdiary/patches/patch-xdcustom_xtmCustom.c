$NetBSD$

--- xdcustom/xtmCustom.c.orig	1997-05-04 22:02:16.000000000 +0000
+++ xdcustom/xtmCustom.c
@@ -231,8 +231,8 @@ static int
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
@@ -615,7 +615,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -641,7 +641,7 @@ static Widget
                                              &do_cust_def[ index ] );
 
     XtAddCallback( doCustBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) doCustCB, (XtPointer) index );
+                   (XtCallbackProc) doCustCB, (XtPointer)(intptr_t)index );
 
   } /* loop */
 
@@ -1451,7 +1451,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Calendar customization? */
     case 0:
@@ -1578,7 +1578,7 @@ static void 
   /* Code. */
 
   /* About window? */
-  if( (int) call_data -> data == 6 ) {
+  if( (intptr_t) call_data -> data == 6 ) {
 
     Widget  tempW;
 
@@ -1590,7 +1590,7 @@ static void 
 
   /* Use the standard help. */
   xtmHlDisplayHelp( appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     custom_window_id, "" );
 
   return;
