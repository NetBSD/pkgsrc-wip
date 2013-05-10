$NetBSD: patch-choosefont.tcl,v 1.1 2013/05/10 13:20:49 francksys Exp $
# Since tk-Tix-8.4.3 tcl scipt must include Tix
--- choosefont.tcl.orig	2013-05-10 06:28:23.000000000 +0000
+++ choosefont.tcl
@@ -5,6 +5,7 @@
 #                         <jan.keirse@pandora.be>			       #
 #									       #
 ################################################################################
+package require Tix
 
 # Restart in tixwish if necessary \
 exec tixwish "$0" "$@"
