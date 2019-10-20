$NetBSD$

Backport fix for newer vala
https://gitlab.gnome.org/GNOME/vte/commit/53690d5cee51bdb7c3f7680d3c22b316b1086f2c

--- bindings/vala/app.vala.orig	2017-05-04 09:46:02.000000000 +0000
+++ bindings/vala/app.vala
@@ -491,7 +491,7 @@ class Window : Gtk.ApplicationWindow
 
     switch (pid) {
     case -1: /* error */
-      printerr("Error forking: %m");
+      printerr("Error forking: %s", strerror(errno));
       break;
     case 0: /* child */ {
       pty.child_setup();
@@ -811,6 +811,8 @@ class App : Gtk.Application
 
   public struct Options
   {
+    //FIXME Merge this struct into App class
+    public int dummy;
     public static bool audible = false;
     public static string? command = null;
     private static string? cjk_ambiguous_width_string = null;
