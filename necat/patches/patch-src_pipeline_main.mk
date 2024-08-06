$NetBSD$

Do not set execute permissions on a non-executable file.

--- src/pipeline/main.mk.orig	2020-08-03 07:31:39.000000000 +0000
+++ src/pipeline/main.mk
@@ -23,7 +23,6 @@ ${TARGET_DIR}/Necat.pm: pipeline/Necat.p
 ${TARGET_DIR}/necat.sh: pipeline/necat.sh
 	@if [ ! -e ${TARGET_DIR} ] ; then mkdir -p ${TARGET_DIR} ; fi
 	cp -pf pipeline/necat.sh ${TARGET_DIR}/necat.sh
-	chmod +x ${TARGET_DIR}/necat.sh
 
 ${TARGET_DIR}/renecat.sh: pipeline/renecat.sh
 	@if [ ! -e ${TARGET_DIR} ] ; then mkdir -p ${TARGET_DIR} ; fi
