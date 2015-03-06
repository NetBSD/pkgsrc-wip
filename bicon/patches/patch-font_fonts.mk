$NetBSD: patch-font_fonts.mk,v 1.2 2015/03/06 18:36:43 mbowie Exp $
Remove Linux'isms per http://daemonforums.org/attachment.php?attachmentid=537&d=1425436939
Patch authored by bcallah@openbsd.org

--- font/fonts.mk.orig	2015-03-05 07:36:42.000000000 -0800
+++ font/fonts.mk	2015-03-05 07:36:53.000000000 -0800
@@ -5,7 +5,6 @@
 		bicon-8x16-512-marks-ltr
 
 ALL_CONSOLE_FONTS_SFM = $(ALL_CONSOLE_FONTS:=.sfm)
-ALL_CONSOLE_FONTS_PSFU = $(ALL_CONSOLE_FONTS:=.psfu)
 
 ALL_SUBSFMS = \
 		bicon-ascii.sub-sfm \
