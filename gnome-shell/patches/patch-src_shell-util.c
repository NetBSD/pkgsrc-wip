$NetBSD$

Quick ugly fix, breaks time string translation/format

--- src/shell-util.c.orig	2020-06-02 23:41:06.254288000 +0000
+++ src/shell-util.c
@@ -212,12 +212,12 @@ shell_util_translate_time_string (const 
   if (locale)
     loc = newlocale (LC_MESSAGES_MASK, locale, (locale_t) 0);
 
-  old_loc = uselocale (loc);
+  //old_loc = uselocale (loc);
 
   sep = strchr (str, '\004');
   res = g_dpgettext (NULL, str, sep ? sep - str + 1 : 0);
 
-  uselocale (old_loc);
+  //uselocale (old_loc);
 
   if (loc != (locale_t) 0)
     freelocale (loc);
