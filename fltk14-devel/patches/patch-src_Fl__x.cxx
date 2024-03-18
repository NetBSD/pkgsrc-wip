$NetBSD$

Upstream patch for slow menubar on NetBSD with Unicode locales:
https://github.com/fltk/fltk/issues/935

--- src/Fl_x.cxx.orig	2024-03-17 02:16:19.000000000 +0000
+++ src/Fl_x.cxx
@@ -1232,17 +1232,45 @@ static void after_display_rescale(float 
 }
 #endif // USE_XFT
 
+#  include "Fl_Int_Vector.H"
+static Fl_Int_Vector xid_vector; // for list of FLTK-created xid's
+
+static bool remove_int_vector(Fl_Int_Vector& v, int val) {
+  unsigned pos;
+  for (pos = 0; pos < v.size(); pos++) {
+    if (v[pos] == val) break;
+  }
+  if (pos >= v.size()) return false;
+  int last = v.pop_back();
+  if (last != val) v[pos] = last;
+  return true;
+}
+
 int fl_handle(const XEvent& thisevent)
 {
   XEvent xevent = thisevent;
   fl_xevent = &thisevent;
   Window xid = xevent.xany.window;
+  
+  // For each DestroyNotify event, determine whether an FLTK-created window
+  // is being destroyed. 
+  // It's true if xid is in xid_vector containing all FLTK-created xid's.
+  bool xid_is_from_fltk_win = false;
+  if (xevent.type == DestroyNotify) {
+    // set whether xid belongs to vector of FLTK-created xid's
+    xid_is_from_fltk_win = remove_int_vector(xid_vector, (int)xid);
+//printf("xid=%ld is_from_fltk_win=%d\n",xid,xid_is_from_fltk_win);
+  }
 
   if (Fl_X11_Screen_Driver::xim_ic && xevent.type == DestroyNotify &&
-        xid != Fl_X11_Screen_Driver::xim_win && !fl_find(xid))
+        xid != Fl_X11_Screen_Driver::xim_win && !fl_find(xid) && !xid_is_from_fltk_win)
   {
+// when using menus: xid is a closed FLTK win, xim_win is non-FLTK
+// after XIM crash: xid is non-FLTK
+// provoke XIM crash: kill process "ibus-daemon --panel disable --xim"
     XIM xim_im;
     xim_im = XOpenIM(fl_display, NULL, NULL, NULL);
+//printf("xid=%lu xim_win=%lu XOpenIM->%p\n", xid,Fl_X11_Screen_Driver::xim_win,xim_im);
     if (!xim_im) {
       /*  XIM server has crashed */
       XSetLocaleModifiers("");
@@ -2372,6 +2400,7 @@ void Fl_X11_Window_Driver::un_maximize()
 void fl_fix_focus(); // in Fl.cxx
 
 Fl_X* Fl_X::set_xid(Fl_Window* win, Window winxid) {
+  xid_vector.push_back(winxid);
   Fl_X *xp = new Fl_X;
   xp->xid = winxid;
   Fl_Window_Driver::driver(win)->other_xid = 0;
