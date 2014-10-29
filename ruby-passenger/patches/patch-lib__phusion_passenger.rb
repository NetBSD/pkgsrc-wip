$NetBSD: patch-lib__phusion_passenger.rb,v 1.4 2014/10/29 12:59:17 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ lib/phusion_passenger.rb
@@ -51,8 +51,7 @@ module PhusionPassenger
 
 	# Directories in which to look for plugins.
 	PLUGIN_DIRS = [
-		"/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
-		"/usr/local/share/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
+		"@PREFIX@/#{GLOBAL_NAMESPACE_DIRNAME}/plugins",
 		"~/#{USER_NAMESPACE_DIRNAME}/plugins"
 	]
 
@@ -258,7 +257,7 @@ private
 			return filename if File.exist?(filename)
 		end
 
-		filename = "/etc/#{GLOBAL_NAMESPACE_DIRNAME}/locations.ini"
+		filename = "@PKG_SYSCONFDIR@/locations.ini"
 		return filename if File.exist?(filename)
 
 		return nil
