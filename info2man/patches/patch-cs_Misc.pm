$NetBSD: patch-cs_Misc.pm,v 1.1 2013/05/14 13:39:50 francksys Exp $

/* Eliminate old-fashioned call for flush.pl */
--- cs/Misc.pm.orig	2003-09-19 23:42:52.000000000 +0000
+++ cs/Misc.pm
@@ -10,7 +10,7 @@ use strict qw(vars);
 
 $::DEBUG=0 if ! defined $::DEBUG;
 
-require 'flush.pl';	# for ::flush()
+# require 'flush.pl';	# for ::flush()
 use cs::Math;
 
 package cs::Misc;
