$NetBSD$

Fix parameter of callback function.

--- src/Browser.cxx.orig	2012-03-23 05:49:17.000000000 +0000
+++ src/Browser.cxx
@@ -1900,7 +1900,7 @@ void Browser::column_labels(const char *
       if (i<nHeader) sides |= 2;
       header_[i] = new BButton(sides, column_labels_[i]);
       header_[i]->parent(this);
-      header_[i]->callback(column_click_cb_, (void*)i);
+      header_[i]->callback(column_click_cb_, &i);
     }
     Group::current(g);
   }
