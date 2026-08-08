$NetBSD$

--- lib/rdoc/options.rb.orig	2008-01-11 01:24:05.000000000 +0000
+++ lib/rdoc/options.rb
@@ -573,7 +573,7 @@ class Options
   
   def check_files
     @files.each do |f|
-      stat = File.stat f rescue error("File not found: #{f}")
+      stat = File.stat f rescue next
       error("File '#{f}' not readable") unless stat.readable?
     end
   end
