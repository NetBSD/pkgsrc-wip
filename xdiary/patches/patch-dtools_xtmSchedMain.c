$NetBSD$

--- dtools/xtmSchedMain.c.orig	1997-05-04 23:16:02.000000000 +0000
+++ dtools/xtmSchedMain.c
@@ -1090,7 +1090,7 @@ static Widget
 
     if( XmIsPushButton( menuFileBu[ index ] ) )
       XtAddCallback( menuFileBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) fileMenuCB, (XtPointer) index );
+                     (XtCallbackProc) fileMenuCB, (XtPointer)(intptr_t)index );
   }
 
   if( flagIsSet( sched_ref -> flags, XTM_SM_ONLY_ONE ) )
@@ -1109,7 +1109,7 @@ static Widget
 
     if( XmIsPushButton( menuEditBu[ index ] ) )
       XtAddCallback( menuEditBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) editMenuCB, (XtPointer) index );
+                     (XtCallbackProc) editMenuCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -1125,10 +1125,10 @@ static Widget
 
     if( XmIsPushButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
     else if( XmIsToggleButton( menuCtrlBu[ index ] ) )
       XtAddCallback( menuCtrlBu[ index ], XmNvalueChangedCallback, 
-                     (XtCallbackProc) ctrlMenuCB, (XtPointer) index );
+                     (XtCallbackProc) ctrlMenuCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -1142,7 +1142,7 @@ static Widget
 
     if( XmIsPushButton( menuOptionsBu[ index ] ) )
       XtAddCallback( menuOptionsBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) optionsMenuCB, (XtPointer) index );
+                     (XtCallbackProc) optionsMenuCB, (XtPointer)(intptr_t)index );
   }
 
 
@@ -1156,7 +1156,7 @@ static Widget
 
     if( XmIsPushButton( menuHelpBu[ index ] ) )
       XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                     (XtCallbackProc) infoCB, (XtPointer) index );
+                     (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1971,7 +1971,7 @@ static void 
   mainW = XtNameToWidget( sched_ref -> scheduleW, "SchedTlBase.SchedTlFo" );
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Confirm actions? */
     case 0:
@@ -2277,7 +2277,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Edit the entry. */
     case 0:
@@ -2401,7 +2401,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Open schedule with the same database. */
     case 0:
@@ -2493,7 +2493,7 @@ static void 
             flagIsSet(   db_info.operations, XTM_DB_FLAG_MODE_WRITE ) )
           can_download = True;
 
-        if( (int) call_data -> data == 4 )
+        if( (intptr_t) call_data -> data == 4 )
           xtmRtDoRemote( sched_ref -> remote_handle, XTM_RT_UPLOAD,
                          db_info.short_name, True, can_download );
         else
@@ -2605,7 +2605,7 @@ static void 
   /* Code. */
 
   /* About window? */
-  if( (int) call_data -> data == 6 ) {
+  if( (intptr_t) call_data -> data == 6 ) {
     xtmHlDisplayAboutWindow( sched_ref -> scheduleW );
 
     return;
@@ -2613,7 +2613,7 @@ static void 
 
   /* Use the standard help. */
   xtmHlDisplayHelp( sched_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     day_view_window_id, "" );
 
   return;
@@ -3020,7 +3020,7 @@ static void 
 
 
   /* Select what to do. */
-  switch( (int) call_data -> data ) {
+  switch( (intptr_t) call_data -> data ) {
 
     /* Appointment editor. */
     case 0:
