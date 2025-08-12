$NetBSD$

--- modules/javafx.web/src/main/native/Source/WebCore/Scripts/generate-unified-sources.sh.orig	2025-08-10 14:18:25.170536421 +0000
+++ modules/javafx.web/src/main/native/Source/WebCore/Scripts/generate-unified-sources.sh
@@ -7,7 +7,7 @@ ARGS=("$@")
 cd $SRCROOT
 
 if [ -z "${BUILD_SCRIPTS_DIR}" ]; then
-    if [ "${DEPLOYMENT_LOCATION}" == "YES" ]; then
+    if [ "${DEPLOYMENT_LOCATION}" = "YES" ]; then
         BUILD_SCRIPTS_DIR="${SDKROOT}${WK_ALTERNATE_WEBKIT_SDK_PATH}${WK_LIBRARY_HEADERS_FOLDER_PATH}/wtf/Scripts"
     else
         BUILD_SCRIPTS_DIR="${BUILT_PRODUCTS_DIR}${WK_LIBRARY_HEADERS_FOLDER_PATH}/wtf/Scripts"
@@ -23,7 +23,7 @@ if [ $# -eq 0 ]; then
 fi
 
 SOURCES="Sources.txt SourcesCocoa.txt platform/SourcesLibWebRTC.txt"
-if [ "${USE_INTERNAL_SDK}" == "YES" ]; then
+if [ "${USE_INTERNAL_SDK}" = "YES" ]; then
     SOURCES="${SOURCES} SourcesCocoaInternalSDK.txt"
 fi
 
