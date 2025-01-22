$NetBSD$

Function sendxjun() is no longer available since FLTK 1.3.

fl_show_iconic() replaced with show_next_window_iconic() for FLTK 1.4.

--- src/WindowUtils.cpp.orig	2014-06-21 21:24:07.000000000 +0000
+++ src/WindowUtils.cpp
@@ -33,7 +33,7 @@
  * These are defined in FLTK as hidden variables for some internal hacks, but are used here.
  * XXX: possible changes in future FLTK versions
  */
-extern char fl_show_iconic;
+//extern char fl_show_iconic;
 extern int  fl_disable_transient_for;
 
 EDELIB_NS_BEGIN
@@ -140,8 +140,8 @@ void window_xid_create(Fl_Window* win, v
 
 		XChangeProperty(fl_display, xp->xid, WM_PROTOCOLS, XA_ATOM, 32, 0, (unsigned char*)&WM_DELETE_WINDOW, 1);
 
-		// send size limits and border:
-		xp->sendxjunk();
+		// send size limits and border (no longer available since FLTK 1.3)
+		//xp->sendxjunk();
 
 		// set the class property, which controls the icon used:
 		if(win->xclass()) {
@@ -194,10 +194,10 @@ void window_xid_create(Fl_Window* win, v
 		hints->input = True;
 		hints->flags = InputHint;
 
-		if(fl_show_iconic) {
+		if(win->show_next_window_iconic()) {
 			hints->flags |= StateHint;
 			hints->initial_state = IconicState;
-			fl_show_iconic = 0;
+			win->show_next_window_iconic(0);
 			showit = 0;
 		}
 
