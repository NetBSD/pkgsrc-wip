$NetBSD$

Function clear_overlay() is no longer available since FLTK 1.3.

--- src/MenuItem.cpp.orig	2014-06-21 21:24:07.000000000 +0000
+++ src/MenuItem.cpp
@@ -305,7 +305,8 @@ menutitle::menutitle(int X, int Y, int W
   set_modal();
   clear_border();
   menu = L;
-  if (L->labelcolor_ || Fl::scheme() || L->labeltype_ > FL_NO_LABEL) clear_overlay();
+  // clear_overlay() is no longer available since FLTK 1.3
+  //if (L->labelcolor_ || Fl::scheme() || L->labeltype_ > FL_NO_LABEL) clear_overlay();
 }
 
 menuwindow::menuwindow(const MenuItem* m, int X, int Y, int Wp, int Hp,
@@ -394,7 +395,8 @@ menuwindow::menuwindow(const MenuItem* m
       w1 = int(fl_width(fl_shortcut_label(m->shortcut_))) + 8;
       if (w1 > hotKeysw) hotKeysw = w1;
     }
-    if (m->labelcolor_ || Fl::scheme() || m->labeltype_ > FL_NO_LABEL) clear_overlay();
+    // clear_overlay() is no longer available since FLTK 1.3
+    //if (m->labelcolor_ || Fl::scheme() || m->labeltype_ > FL_NO_LABEL) clear_overlay();
   }
 
   if (selected >= 0 && !Wp) X -= W/2;
