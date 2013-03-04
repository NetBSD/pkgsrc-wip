$NetBSD: patch-scripts_os-detect.sh,v 1.1 2013/03/04 17:33:01 othyro Exp $

Add NetBSD support.

--- scripts/os-detect.sh.orig	2013-01-06 17:07:22.000000000 +0000
+++ scripts/os-detect.sh
@@ -3,7 +3,7 @@
 
 OS="`uname -s`"
 UNAME="`uname -a`"
-DIST="`uname -r` (`uname -o`)"
+DIST="`uname -r` (`uname -n`)"
 
 if [ "${OS}" = "Linux" ] ; then
   if [ -f /etc/mandriva-release ] ; then
@@ -15,6 +15,8 @@ if [ "${OS}" = "Linux" ] ; then
   elif [ -f /etc/debian_version ] ; then
     DIST="`echo Debian` `cat /etc/debian_version | sed 's/\//-/'`"
   fi
+elif [ "${OS}" = "NetBSD" ] ; then
+  DIST="${OS}"
 fi
 
 OSCFG="arch/${OS}.cfg"
@@ -26,6 +28,9 @@ else
 fi
 DISTCFG="arch/${OS}/$DIST.cfg"
 DISTCFG="`echo ${DISTCFG} | tr " " '_'`"
+if [ "${OS}" = "NetBSD" ] ; then
+  DISTCFG="arch/${OS}.cfg"
+fi
 if [ -f ${DISTCFG} ] ; then
   DISTCFG="Distribution cfg-file (ok) .. `echo ${DISTCFG}`"
 else
