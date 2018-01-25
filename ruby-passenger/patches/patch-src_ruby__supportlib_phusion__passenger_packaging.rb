$NetBSD$

Avoid env based shebangs.

--- src/ruby_supportlib/phusion_passenger/packaging.rb.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/ruby_supportlib/phusion_passenger/packaging.rb
@@ -47,10 +47,6 @@ module PhusionPassenger
     # so that these executables can be run with any Ruby interpreter
     # the user desires.
     EXECUTABLES_WITH_FREE_RUBY = [
-      'passenger',
-      'passenger-config',
-      'passenger-install-apache2-module',
-      'passenger-install-nginx-module'
     ]
 
     # A list of globs which match all files that should be packaged
