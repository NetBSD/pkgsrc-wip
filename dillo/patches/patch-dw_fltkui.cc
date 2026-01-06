$NetBSD$

Avoid ctype(3) undefined behaviours.

--- dw/fltkui.cc.orig	2026-01-06 16:25:07.215514321 +0000
+++ dw/fltkui.cc
@@ -365,14 +365,14 @@ int CustChoice::handle(int e)
       if (k == FL_Enter || k == FL_Down) {
          return Fl_Choice::handle(FL_PUSH); // activate menu
 
-      } else if (isalnum(k)) { // try key as shortcut to menuitem
+      } else if (isalnum((unsigned char)k)) { // try key as shortcut to menuitem
          int t = value()+1 >= size() ? 0 : value()+1;
          while (t != value()) {
              const Fl_Menu_Item *mi = &(menu()[t]);
              if (mi->submenu()) // submenu?
                 ;
              else if (mi->label() && mi->active()) { // menu item?
-                if (k == tolower(mi->label()[0])) {
+                if (k == tolower((unsigned char)mi->label()[0])) {
                    value(mi);
                    return 1; // Let FLTK know we used this key
                 }
