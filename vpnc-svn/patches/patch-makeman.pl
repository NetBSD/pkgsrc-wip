$NetBSD: patch-makeman.pl,v 1.2 2014/02/20 20:53:59 hfath Exp $

--- makeman.pl.orig	2014-02-20 20:27:20.000000000 +0000
+++ makeman.pl
@@ -1,2 +1,2 @@
-#! /usr/bin/env perl
+#! @PERL5@ -w
 
