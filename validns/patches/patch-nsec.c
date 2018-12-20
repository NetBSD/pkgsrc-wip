$NetBSD$

Args to isxxxx() etc. shall be "unsigned char".

--- nsec.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ nsec.c
@@ -133,7 +133,7 @@ void validate_nsec_chain(void)
         freeall_temp();
         s = rr->next_domain;
         t = name;
-        while (*s) *t++ = tolower(*s++);
+        while (*s) *t++ = tolower((unsigned char)*s++);
         *t = 0;
         rr_set = find_rr_set(T_NSEC, name);
         if (!rr_set) {
