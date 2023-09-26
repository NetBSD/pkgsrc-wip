$NetBSD$

Adding NetBSD target.

--- BUILD.SH.orig	2023-09-26 14:04:43.583274833 +0000
+++ BUILD.SH
@@ -58,6 +58,7 @@ if [ "$UNAME" = "AIX" ]; then		WWW_MACH=
 if [ "$UNAME" = "OSF1" ]; then		WWW_MACH=osf1;export WWW_MACH;fi
 if [ "$UNAME" = "BSD/386" ]; then	WWW_MACH=unix;export WWW_MACH;fi
 if [ "$UNAME" = "Linux" ]; then		WWW_MACH=linux;export WWW_MACH;fi
+if [ "$UNAME" = "NetBSD" ]; then	WWW_MACH=netbsd;export WWW_MACH;fi
 if [ "$UNAME" = "A/UX" ]; then		WWW_MACH=aux;export WWW_MACH;fi
 if [ "$UNAME" = "SMP_DC.SOx" ]; then	WWW_MACH=pyramid;export WWW_MACH;fi
 
