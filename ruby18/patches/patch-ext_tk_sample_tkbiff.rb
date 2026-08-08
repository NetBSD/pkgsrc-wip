$NetBSD$

--- ext/tk/sample/tkbiff.rb.orig	2007-02-12 23:01:19.000000000 +0000
+++ ext/tk/sample/tkbiff.rb
@@ -12,7 +12,11 @@ if ARGV.length == 0
   if ENV['MAIL']
     $spool = ENV['MAIL']
   else  
-    $spool = '/var/spool/mail/' + ENV['USER']
+    dir = '/var/mail'
+    unless FileTest.directory?(dir)
+      dir = '/var/spool/mail'
+    end
+    $spool = dir + '/' + ENV['USER']
   end
 else 
   $spool = ARGV[0]
