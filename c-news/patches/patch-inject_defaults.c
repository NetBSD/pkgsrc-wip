$NetBSD: patch-inject_defaults.c,v 1.2 2011/08/17 19:56:09 hfath Exp $

time_t might be int64_t now, adapt.

--- inject/defaults.c.orig	1995-01-02 21:48:38.000000000 +0000
+++ inject/defaults.c
@@ -3,8 +3,10 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
+#include <time.h>
 #include <pwd.h>
 #include <sys/types.h>
 #include "news.h"
@@ -18,7 +20,6 @@ extern FILE *efopen();
 extern char *getenv(), *getlogin();
 extern char *emalloc();
 extern struct passwd *getmypwent();
-extern time_t time();
 
 /* exports */
 char *progname = "";
