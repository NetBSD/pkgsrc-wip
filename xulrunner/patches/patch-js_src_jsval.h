$NetBSD: patch-js_src_jsval.h,v 1.1 2011/03/07 17:29:52 tnn2 Exp $

# Attachment #517107 from
#     https://bugzilla.mozilla.org/show_bug.cgi?id=618485

--- js/src/jsval.h.orig	2011-02-23 05:53:35.000000000 +0000
+++ js/src/jsval.h
@@ -346,6 +346,7 @@ typedef union jsval_layout
         union {
             int32          i32;
             uint32         u32;
+            jsuword        word;
             JSWhyMagic     why;
         } payload;
     } s;
