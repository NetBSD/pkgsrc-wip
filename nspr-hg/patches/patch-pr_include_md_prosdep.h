$NetBSD: patch-pr_include_md_prosdep.h,v 1.2 2014/09/28 14:29:41 thomasklausner Exp $

DragonFly support.

--- pr/include/md/prosdep.h.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/include/md/prosdep.h
@@ -34,7 +34,7 @@ PR_BEGIN_EXTERN_C
 #if defined(AIX)
 #include "md/_aix.h"
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__DragonFly__)
 #include "md/_freebsd.h"
 
 #elif defined(NETBSD)
