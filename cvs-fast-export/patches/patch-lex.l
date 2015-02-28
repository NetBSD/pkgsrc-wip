$NetBSD: patch-lex.l,v 1.1 2015/02/28 10:29:18 ryo-on Exp $

'struct tm' has no member named 'tm_zone' on SunOS
--- lex.l.orig	2014-11-27 11:44:55.000000000 +0000
+++ lex.l
@@ -313,7 +313,7 @@ lex_date(const cvs_number const *n, yysc
     tm.tm_min = n->n[4];
     tm.tm_sec = n->n[5];
     tm.tm_isdst = 0;
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__sun)
     tm.tm_zone = 0;
 #endif
     d = mktime(&tm);
