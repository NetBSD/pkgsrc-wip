$NetBSD: patch-lib_phusion__passenger_platform__info_apache.rb,v 1.1 2013/09/05 10:55:52 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger/platform_info/apache.rb.orig	2013-09-04 10:23:17.692518360 +0000
+++ lib/phusion_passenger/platform_info/apache.rb
@@ -216,6 +216,8 @@ module PlatformInfo
 			elsif File.exist?("/etc/httpd/envvars")
 				return "/etc/httpd/envvars"
 			end
+		elsif httpd_dir == "@PREFIX@"
+			return "@PREFIX@/sbin/envvars"
 		end
 		
 		conf_dir = File.expand_path(File.dirname(httpd) + "/../conf")
