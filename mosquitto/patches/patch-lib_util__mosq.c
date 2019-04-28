$NetBSD$

Something in the tests breaks because __GLIBC_PREREQ is not defined.
See https://github.com/eclipse/mosquitto/issues/1242

--- lib/util_mosq.c.orig	2019-04-26 16:07:59.000000000 +0000
+++ lib/util_mosq.c
@@ -29,7 +29,7 @@ Contributors:
 #endif
 
 #if !defined(WITH_TLS) && defined(__linux__)
-#  if defined(__GLIBC__) && __GLIBC_PREREQ(2, 25)
+#  if defined(__GLIBC__)
 #    include <sys/random.h>
 #  endif
 #endif
@@ -325,7 +325,7 @@ int util__random_bytes(void *bytes, int 
 	if(RAND_bytes(bytes, count) == 1){
 		rc = MOSQ_ERR_SUCCESS;
 	}
-#elif defined(__GLIBC__) && __GLIBC_PREREQ(2, 25)
+#elif defined(__GLIBC__)
 	if(getrandom(bytes, count, 0) == 0){
 		rc = MOSQ_ERR_SUCCESS;
 	}
