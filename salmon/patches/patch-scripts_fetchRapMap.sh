$NetBSD$

# Eliminate build phase download
--- scripts/fetchRapMap.sh.orig	2018-09-11 14:54:51 UTC
+++ scripts/fetchRapMap.sh
@@ -30,7 +30,7 @@ EXPECTED_SHA256=b863548383448c21a862cc56
 
 
 mkdir -p ${EXTERNAL_DIR}
-curl -k -L https://github.com/COMBINE-lab/RapMap/archive/${SVER}.zip -o ${EXTERNAL_DIR}/rapmap.zip
+cp ${DISTDIR}/${DIST_SUBDIR}/${SVER}.zip ${EXTERNAL_DIR}/rapmap.zip
 
 hashcheck=""
 if exists sha256sum; then
