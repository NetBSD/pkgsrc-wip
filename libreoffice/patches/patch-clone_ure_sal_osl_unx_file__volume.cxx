$NetBSD: patch-clone_ure_sal_osl_unx_file__volume.cxx,v 1.1 2011/05/18 12:57:43 thomasklausner Exp $

--- clone/ure/sal/osl/unx/file_volume.cxx.orig	2011-05-17 10:44:26.000000000 +0000
+++ clone/ure/sal/osl/unx/file_volume.cxx
@@ -75,7 +75,9 @@ static const sal_Char* MOUNTTAB="/etc/mt
 #include <sys/param.h>
 #include <sys/ucred.h>
 #include <sys/mount.h>
+#ifndef NetBSD
 #include <ufs/ufs/quota.h>
+#endif
 #define  HAVE_STATFS_H
 
 /* No mounting table on *BSD
