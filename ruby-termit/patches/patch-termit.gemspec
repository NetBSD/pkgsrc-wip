$NetBSD: patch-termit.gemspec,v 1.1 2015/08/26 15:39:51 yhardy Exp $

Don't use git to get the file list.

--- termit.gemspec.orig	2016-09-07 12:55:45.000000000 +0000
+++ termit.gemspec
@@ -11,7 +11,7 @@ Gem::Specification.new do |gem|
   gem.summary       = %q{ Translations with speech synthesis in your terminal }
   gem.description   = %q{ Termit is an easy way to translate stuff and use speech synthesis in your terminal. }
   gem.homepage      = "http://github.com/pawurb/termit"
-  gem.files         = `git ls-files`.split("\n")
+  gem.files         = `find . '!' -type d | sed s,./,,`.split("\n")
   gem.executables   = ['termit']
   gem.test_files    = gem.files.grep(%r{^(spec)/})
   gem.require_paths = ["lib"]
