$NetBSD: patch-tasks_build.js,v 1.1 2015/02/22 20:10:34 mbowie Exp $
get_build_props target fails for source not cloned from git

--- tasks/build.js.orig	2015-02-22 14:14:26.000000000 +0000
+++ tasks/build.js	2015-02-22 14:14:33.000000000 +0000
@@ -1,6 +1,5 @@
 module.exports = function (grunt) {
   grunt.registerTask('build', [
-    'get_build_props',
     'clean:target',
     'clean:build',
     'require_css_deps:copy',
