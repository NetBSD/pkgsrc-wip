$NetBSD: patch-lib__phusion_passenger.rb,v 1.2 2013/09/05 10:55:52 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger.rb.orig	2013-08-19 11:39:38.000000000 +0000
+++ lib/phusion_passenger.rb
@@ -49,8 +49,7 @@ module PhusionPassenger
 	
 	# Directories in which to look for plugins.
 	PLUGIN_DIRS = [
-		"/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
-		"/usr/local/share/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
+		"@PREFIX@/share/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
 		"~/#{USER_NAMESPACE_DIRNAME}/plugins"
 	]
 	
@@ -184,7 +183,7 @@ private
 			return filename if File.exist?(filename)
 		end
 
-		filename = "/etc/#{GLOBAL_NAMESPACE_DIRNAME}/locations.ini"
+		filename = "@PKG_SYSCONFDIR@/locations.ini"
 		return filename if File.exist?(filename)
 
 		return nil
