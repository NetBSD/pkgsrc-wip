$NetBSD: patch-core_utils.rb,v 1.1.1.1 2011/10/08 11:12:17 obache Exp $

* use included escape library instead of system one.

--- core/utils.rb.orig	2011-08-27 18:49:12.000000000 +0000
+++ core/utils.rb
@@ -30,7 +30,7 @@ RUBY_VERSION_ARRAY = RUBY_VERSION.split(
 require File.join(File::dirname(__FILE__), 'miquire')
 
 Dir::chdir(File::dirname(__FILE__))
-miquire :lib, 'escape'
+miquire :lib, 'miku/escape'
 miquire :lib, 'lazy'
 
 # すべてのクラスにメモ化機能を
