$NetBSD$

Verify SSL certificates.

--- lib/ghi/client.rb.orig	2017-08-21 21:04:43.607885825 +0000
+++ lib/ghi/client.rb
@@ -125,7 +125,6 @@ module GHI
       end
 
       http.use_ssl = true
-      http.verify_mode = OpenSSL::SSL::VERIFY_NONE # FIXME 1.8.7
 
       GHI.v? and puts "\r===> #{method.to_s.upcase} #{path} #{req.body}"
       res = http.start { http.request req }
