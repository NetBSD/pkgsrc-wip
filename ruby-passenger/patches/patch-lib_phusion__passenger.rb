$NetBSD: patch-lib_phusion__passenger.rb,v 1.1 2015/04/02 15:40:15 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ lib/phusion_passenger.rb
@@ -51,8 +51,7 @@ module PhusionPassenger
 
   # Directories in which to look for plugins.
   PLUGIN_DIRS = [
-    "/usr/share/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
-    "/usr/local/share/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
+    "@PREFIX@/#{GLOBAL_NAMESPACE_DIRNAME_}/plugins",
     "~/#{USER_NAMESPACE_DIRNAME_}/plugins"
   ]
 
@@ -264,7 +263,7 @@ private
       return filename if File.exist?(filename)
     end
 
-    filename = "/etc/#{GLOBAL_NAMESPACE_DIRNAME_}/locations.ini"
+    filename = "@PKG_SYSCONFDIR@/locations.ini"
     return filename if File.exist?(filename)
 
     return nil
