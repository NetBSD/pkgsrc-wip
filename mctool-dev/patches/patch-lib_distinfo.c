$NetBSD$

In file included from /usr/include/string.h:154,
                 from distinfo.c:40:
In function '__strncpy_ichk',
    inlined from 'parsedistinfo' at distinfo.c:357:2,
    inlined from 'readdistinfo' at distinfo.c:448:8:
/usr/include/ssp/string.h:91:1: error: '__builtin_strncpy' specified bound 128 equals destination size [-Werror=stringop-truncation]
   91 | __ssp_bos_icheck3_restrict(strncpy, char *, const char *)
      | ^~~~~~~~~~~~~~~~~~~~~~~~~~

--- lib/distinfo.c.orig	2026-04-27 14:34:38.654216613 +0000
+++ lib/distinfo.c
@@ -354,7 +354,7 @@ parsedistinfo(char *text, size_t nentries)
 		errx(1, "overlong rcsid");
 	*p++ = '\0';
 	L++;
-	strncpy(tab->dit_rcsid, text, sizeof(tab->dit_rcsid));
+	memcpy(tab->dit_rcsid, text, strlen(text));
 
 	/*
 	 * Parse all the lines.
