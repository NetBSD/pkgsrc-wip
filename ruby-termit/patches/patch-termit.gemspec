$NetBSD: patch-termit.gemspec,v 1.1 2015/08/26 15:39:51 yhardy Exp $

Don't use git to get the file list.

--- termit.gemspec.orig	2015-03-15 21:13:38.000000000 +0000
+++ termit.gemspec
@@ -11,7 +11,7 @@ Gem::Specification.new do |gem|
   gem.summary       = %q{Google Translate in your terminal}
   gem.description   = %q{ Termit is an easy way to use all the Google Translate goodies straight from your terminal. }
   gem.homepage      = "http://github.com/pawurb/termit"
-  gem.files         = `git ls-files`.split("\n")
+  gem.files         = `find . '!' -type d | sed s,./,,`.split("\n")
   gem.executables   = ['termit']
   gem.test_files    = gem.files.grep(%r{^(spec)/})
   gem.require_paths = ["lib"]
