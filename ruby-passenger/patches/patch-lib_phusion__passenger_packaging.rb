$NetBSD: patch-lib_phusion__passenger_packaging.rb,v 1.2 2015/04/02 15:40:15 fhajny Exp $

Disable upstream shebang handling, we deal with it ourselves.
--- lib/phusion_passenger/packaging.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ lib/phusion_passenger/packaging.rb
@@ -62,7 +62,9 @@ module PhusionPassenger
       'passenger',
       'passenger-config',
       'passenger-install-apache2-module',
-      'passenger-install-nginx-module'
+      'passenger-install-nginx-module',
+      'passenger-memory-stats',
+      'passenger-status'
     ]
 
     # A list of globs which match all files that should be packaged
