$NetBSD$

Remove default value for parameter.

--- fluid/FluidType.h.orig	2012-03-23 05:49:17.000000000 +0000
+++ fluid/FluidType.h
@@ -44,7 +44,7 @@
 class FLUID_API FluidType {
 
   friend class Widget_Browser;
-  friend fltk::Widget *make_type_browser(int,int,int,int,const char *l=0);
+  friend fltk::Widget *make_type_browser(int,int,int,int,const char *l);
   friend class WindowType;
   virtual void setlabel(const char *); // virtual part of label(char*)
 
