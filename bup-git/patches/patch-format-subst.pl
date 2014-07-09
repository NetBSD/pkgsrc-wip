$NetBSD: patch-format-subst.pl,v 1.1 2014/07/09 04:02:05 thomasklausner Exp $

The shallow checkouts used by pkgsrc do not have tag information,
so git describe will alwways fail. Ignore the error.

--- format-subst.pl.orig	2014-07-09 00:48:14.000000000 +0000
+++ format-subst.pl
@@ -19,7 +19,7 @@ while (<>) {
     s{
 	\$Format:\%d\$
     }{
-	my $tag = fix(ex('git describe --match="[0-9]*"'));
+	my $tag = fix('git describe --match="[0-9]*"');
 	"(tag: bup-$tag)"
     }ex;
     
