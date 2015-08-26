$NetBSD: patch-delegate_it.gemspec,v 1.1 2015/08/26 15:30:34 yhardy Exp $

Don't use git to get the file list.

--- delegate_it.gemspec.orig	2015-03-16 08:15:43.000000000 +0000
+++ delegate_it.gemspec
@@ -11,7 +11,7 @@ Gem::Specification.new do |gem|
   gem.summary       = %q{ A drop in replacement for ActiveSupport delegate method in non Rails projects. }
   gem.description   = %q{ delegate_it gem provides an easy way to use ActiveSupport like delegate method in your non Rails projects. }
   gem.homepage      = "http://github.com/pawurb/delegate_it"
-  gem.files         = `git ls-files`.split("\n")
+  gem.files         = `find . '!' -type d | sed s,./,,`.split("\n")
   gem.test_files    = gem.files.grep(%r{^(spec)/})
   gem.require_paths = ["lib"]
   gem.license       = "MIT"
