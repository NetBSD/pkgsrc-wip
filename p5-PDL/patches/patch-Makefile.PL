$NetBSD$

Honor LDFLAGS.

--- Makefile.PL.orig	2017-04-30 16:32:41.000000000 +0000
+++ Makefile.PL
@@ -584,7 +584,7 @@ EOPS
 # support the `$<` variable in explicit rules
 $text .= <<EOT if $^O !~ /MSWin/;
 pdl$Config::Config{exe_ext} : pdl.c
-	\$(CC) \$(CFLAGS) \$(CPPFLAGS) pdl.c -o \$\@
+	\$(CC) \$(CFLAGS) \$(LDFLAGS) \$(CPPFLAGS) pdl.c -o \$\@
 EOT
 
 $text .= << 'EOT' if $^O =~ /MSWin/;
