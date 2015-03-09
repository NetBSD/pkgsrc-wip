$NetBSD: patch-format-subst.pl,v 1.2 2015/03/09 22:36:41 thomasklausner Exp $

The shallow checkouts used by pkgsrc do not have tag information,
so git describe will always fail. Ignore the error.

--- format-subst.pl.orig	2015-03-09 18:56:24.000000000 +0000
+++ format-subst.pl
@@ -19,7 +19,7 @@ while (<>) {
     s{
 	\$Format:\%d\$
     }{
-	my $tag = fix(ex('git describe --always --match="[0-9]*"'));
+	my $tag = fix('git describe --always --match="[0-9]*"');
 	"(tag: bup-$tag)"
     }ex;
     
