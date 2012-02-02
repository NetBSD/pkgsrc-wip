$NetBSD: patch-plugins_sudoers_logging.c,v 1.1.1.1 2012/02/02 23:54:18 mrampke Exp $

Make sure CODESET is actually defined, for the sake of

--- plugins/sudoers/logging.c.orig	2011-10-21 13:01:25.000000000 +0000
+++ plugins/sudoers/logging.c
@@ -545,7 +545,7 @@ send_mail(const char *fmt, ...)
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
