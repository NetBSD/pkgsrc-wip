$NetBSD$

--- src/app.vala.orig	2015-04-28 21:51:21.000000000 +0000
+++ src/app.vala
@@ -257,7 +257,7 @@ class Window : Gtk.ApplicationWindow
 
     switch (pid) {
     case -1: /* error */
-      printerr("Error forking: %m");
+      printerr("Error forking: %s", strerror(errno));
       break;
     case 0: /* child */ {
       pty.child_setup();
