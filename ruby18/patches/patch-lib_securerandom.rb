$NetBSD$

--- lib/securerandom.rb.orig	2011-12-10 12:17:33.000000000 +0000
+++ lib/securerandom.rb
@@ -65,7 +65,6 @@ module SecureRandom
       flags = File::RDONLY
       flags |= File::NONBLOCK if defined? File::NONBLOCK
       flags |= File::NOCTTY if defined? File::NOCTTY
-      flags |= File::NOFOLLOW if defined? File::NOFOLLOW
       begin
         File.open("/dev/urandom", flags) {|f|
           unless f.stat.chardev?
