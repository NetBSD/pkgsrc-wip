$NetBSD$

Address -Wint-conversion warnings and properly cast to intptr_t,
from NetBSD external/bsd/tmux/dist/tty-term.c,-r1.5 by <christos>.

--- tty-term.c.orig	2018-07-27 13:01:14.000000000 +0000
+++ tty-term.c
@@ -616,14 +616,14 @@ tty_term_string3(struct tty_term *term, 
 const char *
 tty_term_ptr1(struct tty_term *term, enum tty_code_code code, const void *a)
 {
-	return (tparm((char *) tty_term_string(term, code), a, 0, 0, 0, 0, 0, 0, 0, 0));
+	return (tparm((char *) tty_term_string(term, code), (intptr_t)a, 0, 0, 0, 0, 0, 0, 0, 0));
 }
 
 const char *
 tty_term_ptr2(struct tty_term *term, enum tty_code_code code, const void *a,
     const void *b)
 {
-	return (tparm((char *) tty_term_string(term, code), a, b, 0, 0, 0, 0, 0, 0, 0));
+	return (tparm((char *) tty_term_string(term, code), (intptr_t)a, (intptr_t)b, 0, 0, 0, 0, 0, 0, 0));
 }
 
 int
