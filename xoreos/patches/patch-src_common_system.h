$NetBSD: patch-src_common_system.h,v 1.2 2015/09/05 23:04:36 yhardy Exp $

Make sure that std::rand() is defined for all the files
where it is needed. Should actually be done this way:

https://github.com/xoreos/xoreos/commit/d678a6f7f9a9850123a512da89efe6f3a7d3e0e1

--- src/common/system.h.orig	2015-07-27 08:05:52.000000000 +0000
+++ src/common/system.h
@@ -97,6 +97,7 @@
 	#endif
 
 #elif defined(UNIX)
+	#include <cstdlib>
 
 	#if defined(HAVE_CONFIG_H)
 		#if defined(WORDS_BIGENDIAN)
