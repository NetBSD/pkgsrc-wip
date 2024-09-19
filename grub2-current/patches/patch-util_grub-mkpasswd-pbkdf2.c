$NetBSD: patch-util_grub-mkpasswd-pbkdf2.c,v 1.1 2013/09/09 09:47:45 gregoire Exp $

Assume that the random generator is fine on NetBSD.

--- util/grub-mkpasswd-pbkdf2.c.orig	2013-09-09 09:39:11.000000000 +0000
+++ util/grub-mkpasswd-pbkdf2.c
@@ -112,7 +112,7 @@ hexify (char *hex, grub_uint8_t *bin, gr
 static int
 grub_get_random (void *out, grub_size_t len)
 {
-#if ! defined (__linux__) && ! defined (__FreeBSD__)
+#if ! defined (__linux__) && ! defined (__FreeBSD__) && ! defined (__NetBSD__)
   /* TRANSLATORS: The generator might still be secure just GRUB isn't sure about it.  */
   printf ("%s", _("WARNING: your random generator isn't known to be secure\n"));
 #warning "your random generator isn't known to be secure"
