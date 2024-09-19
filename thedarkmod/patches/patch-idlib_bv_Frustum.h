$NetBSD$

There's no reason to not always include assert.h when using assert.

--- idlib/bv/Frustum.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/bv/Frustum.h
@@ -16,9 +16,7 @@
 #ifndef __BV_FRUSTUM_H__
 #define __BV_FRUSTUM_H__
 
-#ifdef __linux__
 #include <cassert>
-#endif
 
 /*
 ===============================================================================
