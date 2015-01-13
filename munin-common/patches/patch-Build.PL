$NetBSD: patch-Build.PL,v 1.1 2015/01/13 15:36:02 fhajny Exp $

Add missing module_name so that Munin::Common becomes a valid Perl Module.

--- common/Build.PL.orig	2014-11-24 21:46:24.000000000 +0000
+++ common/Build.PL
@@ -1,6 +1,7 @@
 use Module::Build;
 
 my $build = Module::Build->new(
+    module_name    => 'Munin::Common',
     dist_name      => 'Munin::Common',
     dist_version   => '0.0.0',
     dist_author    => 'The Munin Team <fix@example.com>',
