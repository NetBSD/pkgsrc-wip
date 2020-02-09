$NetBSD$

--- libgcc/crtstuff.c.orig	2020-02-09 13:44:00.000000000 +0000
+++ libgcc/crtstuff.c
@@ -156,7 +156,7 @@ call_ ## FUNC (void)					\
 #endif
 
 #ifdef __MORPHOS__
-static const char __EH_FRAME_BEGIN__[];
+extern const char __EH_FRAME_BEGIN__[];
 #endif
 
 /* We do not want to add the weak attribute to the declarations of these
