$NetBSD$

--- Makefile.PL.orig	2008-11-11 17:54:33.000000000 +0000
+++ Makefile.PL
@@ -11,6 +11,5 @@ all_from 'lib/Sub/Prototype.pm';
 requires 'XSLoader';
 requires 'Sub::Exporter';
 
-extra_tests();
 
 WriteAll;
