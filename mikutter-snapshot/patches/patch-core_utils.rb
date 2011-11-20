$NetBSD: patch-core_utils.rb,v 1.3 2011/11/20 08:51:16 obache Exp $

* use included escape library instead of system one.

--- core/utils.rb.orig	2011-11-11 15:33:04.000000000 +0000
+++ core/utils.rb
@@ -33,7 +33,7 @@ Dir::chdir(File::dirname(__FILE__))
 ['.', 'lib', 'miku'].each{|path|
   $LOAD_PATH.push(File.expand_path(File.join(Dir.pwd, path)))
 }
-miquire :lib, 'escape'
+miquire :lib, 'miku/escape'
 miquire :lib, 'lazy'
 
 # すべてのクラスにメモ化機能を
