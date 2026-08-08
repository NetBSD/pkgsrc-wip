$NetBSD$

--- lib/webrick/httpstatus.rb.orig	2010-06-10 05:23:49.000000000 +0000
+++ lib/webrick/httpstatus.rb
@@ -12,7 +12,7 @@ module WEBrick
 
   module HTTPStatus
 
-    class Status      < StandardError
+    class Status < StandardError
       def initialize(*args)
         args[0] = AccessLog.escape(args[0]) unless args.empty?
         super(*args)
