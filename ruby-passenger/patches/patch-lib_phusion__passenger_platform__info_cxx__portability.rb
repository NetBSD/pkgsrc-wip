$NetBSD: patch-lib_phusion__passenger_platform__info_cxx__portability.rb,v 1.1 2013/09/05 10:55:52 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger/platform_info/cxx_portability.rb.orig	2013-08-27 13:44:41.855788052 +0000
+++ lib/phusion_passenger/platform_info/cxx_portability.rb
@@ -32,7 +32,7 @@ module PlatformInfo
 	# for portability reasons. These flags should be specified as last
 	# when invoking the compiler.
 	def self.portability_cflags
-		flags = ["-D_REENTRANT -I/usr/local/include"]
+		flags = ["-D_REENTRANT -I@PREFIX@/include"]
 		
 		# There are too many implementations of of the hash map!
 		# Figure out the right one.
