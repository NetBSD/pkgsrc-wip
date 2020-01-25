$NetBSD: patch-storage_ndb_mcc_frontend_dojo_dojox_mobile_build_build.sh,v 1.1 2016/09/16 06:49:11 adam Exp $

Portability.

--- storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh.orig	2019-12-09 19:53:17.000000000 +0000
+++ storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh
@@ -14,10 +14,10 @@ optimize=closure
 profile=mobile
 dir=release-mobile-separate
 #standalone=standaloneScrollable=true
-if [ "$1" == "single" ]; then
+if [ "$1" = "single" ]; then
   profile=mobile-all
 fi
-if [ "$1" == "single" ]; then
+if [ "$1" = "single" ]; then
   dir=release-mobile-single
 fi
 shift 1
