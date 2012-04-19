$NetBSD: patch-bin_zkEnv.sh,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

Use a sane default prefix.
--- bin/zkEnv.sh.orig	2012-04-18 17:54:17.089253486 +0000
+++ bin/zkEnv.sh
@@ -23,7 +23,7 @@
 # or the conf directory that is
 # a sibling of this script's directory
 
-ZOOBINDIR=${ZOOBINDIR:-/usr/bin}
+ZOOBINDIR=${ZOOBINDIR:-@PREFIX@}
 ZOOKEEPER_PREFIX=${ZOOBINDIR}/..
 
 if [ "x$ZOOCFGDIR" = "x" ]
