$NetBSD$

SIGTERM and kill are defined in signal.h which is not included.
This problem occurs on NetBSD-7.99 with clang, running 'make test'
https://gitlab.com/gnutls/gnutls/issues/80

--- tests/utils.h.orig	2016-02-27 21:26:39.000000000 +0000
+++ tests/utils.h
@@ -25,6 +25,7 @@
 
 #include <string.h>
 #include <stdarg.h>
+#include <signal.h>
 #include <gnutls/gnutls.h>
 #include <gnutls/pkcs11.h>
 
