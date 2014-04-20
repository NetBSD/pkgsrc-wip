$NetBSD: patch-sys_unix_nethack.sh,v 1.1 2014/04/20 14:53:48 rhialto Exp $

Correct XUSERFILESEARCHPATH: unnethack uses class NetHack, but the
resource file is named UnNetHack.ad.

--- sys/unix/nethack.sh.orig	2013-12-08 15:00:25.000000000 +0000
+++ sys/unix/nethack.sh
@@ -6,11 +6,11 @@ export HACKDIR
 HACK=$HACKDIR/nethack
 MAXNROFPLAYERS=4
 
-# Since Nethack.ad is installed in HACKDIR, add it to XUSERFILESEARCHPATH
+# Since UnNethack.ad is installed in HACKDIR, add it to XUSERFILESEARCHPATH
 case "x$XUSERFILESEARCHPATH" in
-x)	XUSERFILESEARCHPATH="$HACKDIR/%N.ad"
+x)	XUSERFILESEARCHPATH="$HACKDIR/Un%N.ad"
 	;;
-*)	XUSERFILESEARCHPATH="$XUSERFILESEARCHPATH:$HACKDIR/%N.ad"
+*)	XUSERFILESEARCHPATH="$XUSERFILESEARCHPATH:$HACKDIR/Un%N.ad"
 	;;
 esac
 export XUSERFILESEARCHPATH
