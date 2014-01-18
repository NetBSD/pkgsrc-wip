$NetBSD: patch-src_collectd.c,v 1.1 2014/01/18 19:13:53 fhajny Exp $

sg_init() expects an arg.
--- src/collectd.c.orig	2013-08-18 10:24:25.065973312 +0000
+++ src/collectd.c
@@ -288,7 +288,7 @@ static int do_init (void)
 #endif
 
 #if HAVE_LIBSTATGRAB
-	if (sg_init ())
+	if (sg_init (0))
 	{
 		ERROR ("sg_init: %s", sg_str_error (sg_get_error ()));
 		return (-1);
