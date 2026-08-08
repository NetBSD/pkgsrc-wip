$NetBSD$

--- lib/drb/eq.rb.orig	2007-02-12 23:01:19.000000000 +0000
+++ lib/drb/eq.rb
@@ -1,5 +1,3 @@
-require 'drb/drb'
-
 module DRb
   class DRbObject
     def ==(other)
