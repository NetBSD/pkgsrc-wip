$NetBSD$

Also look in /usr/X11R7.

From upstream pull request #362:

 <https://github.com/9fans/plan9port/pull/362>

--- src/cmd/devdraw/mkwsysrules.sh.orig	2020-06-22 15:22:27.000000000 +0000
+++ src/cmd/devdraw/mkwsysrules.sh
@@ -7,6 +7,8 @@ if [ "x$X11" = "x" ]; then 
 		X11=/usr/X11R6
 	elif [ -d /usr/local/X11R6 ]; then
 		X11=/usr/local/X11R6
+	elif [ -d /usr/X11R7 ]; then
+		X11=/usr/X11R7
 	elif [ -d /usr/X ]; then
 		X11=/usr/X
 	elif [ -d /usr/openwin ]; then	# for Sun
