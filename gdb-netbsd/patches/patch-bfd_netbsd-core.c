$NetBSD$

--- bfd/netbsd-core.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ bfd/netbsd-core.c
@@ -275,7 +275,7 @@ const bfd_target core_netbsd_vec =
     0,				/* Symbol prefix.  */
     ' ',			/* ar_pad_char.  */
     16,				/* ar_max_namelen.  */
-    0,				/* Match priority.  */
+    0,				/* match priority.  */
     NO_GET64, NO_GETS64, NO_PUT64,	/* 64 bit data.  */
     NO_GET, NO_GETS, NO_PUT,		/* 32 bit data.  */
     NO_GET, NO_GETS, NO_PUT,		/* 16 bit data.  */
