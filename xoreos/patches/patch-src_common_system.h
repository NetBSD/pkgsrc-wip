$NetBSD: patch-src_common_system.h,v 1.1 2015/09/05 16:05:10 yhardy Exp $

Make sure that std::rand() is defined for all the files
where it is needed.

--- src/common/system.h.orig	2015-07-27 08:05:52.000000000 +0000
+++ src/common/system.h
@@ -97,6 +97,7 @@
 	#endif
 
 #elif defined(UNIX)
+	#include <cstdlib>
 
 	#if defined(HAVE_CONFIG_H)
 		#if defined(WORDS_BIGENDIAN)
