$NetBSD$

# Patch to fix hardcoded path for default conf file.
--- install.pl.orig	2017-07-04 20:38:24.361441000 +0000
+++ install.pl
@@ -2601,7 +2601,7 @@ if ( ($PROMPTcopy_web_lang =~ /y/i) || (
 	print "Static language files no longer available, use dynamic language features.\n";
 	}
 
-if ($PATHconf !~ /\/etc\/astguiclient.conf/)
+if ($PATHconf !~ /\/usr\/pkg\/etc\/astguiclient.conf/)
 	{
 	print "Using non-default conf file, adjusting hard-coded paths...\n";
 
