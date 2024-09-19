$NetBSD$

--- src/gsm/gsm_utils.c.orig	2019-01-21 13:50:43.000000000 +0000
+++ src/gsm/gsm_utils.c
@@ -100,7 +100,7 @@
 
 #if (!EMBEDDED)
 /* FIXME: this can be removed once we bump glibc requirements to 2.25: */
-#if defined(__GLIBC_PREREQ) && __GLIBC_PREREQ(2,25)
+#if false // XXX defined(__GLIBC_PREREQ) && __GLIBC_PREREQ(2,25)
 #pragma message ("glibc " OSMO_STRINGIFY_VAL(__GLIBC__) "." OSMO_STRINGIFY_VAL(__GLIBC_MINOR__) " random detected")
 #include <sys/random.h>
 #undef USE_GNUTLS
@@ -447,7 +447,7 @@ int osmo_get_rand_id(uint8_t *out, size_
 	if (len > OSMO_MAX_RAND_ID_LEN)
                return -E2BIG;
 #if (!EMBEDDED)
-#if defined(__GLIBC_PREREQ) && __GLIBC_PREREQ(2,25)
+#if false // XXX defined(__GLIBC_PREREQ) && __GLIBC_PREREQ(2,25)
 	rc = getrandom(out, len, GRND_NONBLOCK);
 #elif HAVE_DECL_SYS_GETRANDOM
 #pragma message ("Using direct syscall access for getrandom(): consider upgrading to glibc >= 2.25")
