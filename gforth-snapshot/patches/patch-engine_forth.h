$NetBSD$

Avoid problem with macro of the same name on NetBSD.

--- engine/forth.h.orig	2025-03-18 09:57:47.878480530 +0000
+++ engine/forth.h
@@ -556,7 +556,7 @@ char *cstr(Char *from, UCell size);
 char *tilde_cstr(Char *from, UCell size);
 Cell opencreate_file(char *s, Cell wfam, int flags, Cell *wiorp);
 DCell timeval2us(struct timeval *tvp);
-DCell timespec2ns(struct timespec *tvp);
+DCell gf_timespec2ns(struct timespec *tvp);
 void cmove(Char *c_from, Char *c_to, UCell u);
 void cmove_up(Char *c_from, Char *c_to, UCell u);
 Cell compare(Char *c_addr1, UCell u1, Char *c_addr2, UCell u2);
