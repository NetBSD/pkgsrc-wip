$NetBSD$

Add missing library.

--- PatternPaint.pro.orig	2016-12-13 10:57:34.000000000 +0000
+++ PatternPaint.pro
@@ -88,6 +88,8 @@ win32 {
     RC_ICONS += images/patternpaint.ico
 }
 
+LIBS+=	-lusb-1.0
+
 DISTFILES += \
     ../uncrustify.cfg \
     gitversion.pri
