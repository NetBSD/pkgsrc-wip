$NetBSD: patch-lib_phusion__passenger_platform__info_cxx__portability.rb,v 1.2 2014/05/06 13:40:31 fhajny Exp $

Fix default paths.
--- lib/phusion_passenger/platform_info/cxx_portability.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ lib/phusion_passenger/platform_info/cxx_portability.rb
@@ -114,7 +114,7 @@ private
 	private_class_method :check_hash_map
 
 	def self.default_extra_c_or_cxxflags(cc_or_cxx)
-		flags = ["-D_REENTRANT", "-I/usr/local/include"]
+		flags = ["-D_REENTRANT", "-I@PREFIX@/include"]
 
 		if !send("#{cc_or_cxx}_is_sun_studio?")
 			flags << "-Wall -Wextra -Wno-unused-parameter -Wno-parentheses -Wpointer-arith -Wwrite-strings -Wno-long-long"
