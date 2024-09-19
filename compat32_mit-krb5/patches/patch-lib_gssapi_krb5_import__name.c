$NetBSD: patch-lib_gssapi_krb5_import__name.c,v 1.1 2018/12/21 15:45:13 adam Exp $

Add DragonFly support. Fallback to LINE_MAX if BUFSIZ is not defined.

--- lib/gssapi/krb5/import_name.c.orig	Sat Dec 11 20:12:52 2010
+++ lib/gssapi/krb5/import_name.c	Sat Dec 11 20:13:40 2010
@@ -28,10 +28,15 @@
 #include "gssapiP_krb5.h"
 
 #ifndef NO_PASSWORD
+#include <limits.h>
 #include <pwd.h>
 #include <stdio.h>
 #endif
 
+#ifndef BUFSIZ
+#define BUFSIZ LINE_MAX
+#endif
+
 #ifdef HAVE_STRING_H
 #include <string.h>
 #else
