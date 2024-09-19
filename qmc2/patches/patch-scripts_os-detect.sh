$NetBSD: patch-scripts_os-detect.sh,v 1.2 2014/01/02 19:36:06 thomasklausner Exp $

Add NetBSD support.

--- scripts/os-detect.sh.orig	2013-12-17 05:55:28.000000000 +0000
+++ scripts/os-detect.sh
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
