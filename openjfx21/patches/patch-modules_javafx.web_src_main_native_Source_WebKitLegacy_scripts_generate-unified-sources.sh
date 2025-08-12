$NetBSD$

--- modules/javafx.web/src/main/native/Source/WebKitLegacy/scripts/generate-unified-sources.sh.orig	2025-08-10 14:15:56.096757442 +0000
+++ modules/javafx.web/src/main/native/Source/WebKitLegacy/scripts/generate-unified-sources.sh
@@ -7,7 +7,7 @@ ARGS=("$@")
 cd $SRCROOT
 
 if [ -z "${BUILD_SCRIPTS_DIR}" ]; then
-    if [ "${DEPLOYMENT_LOCATION}" == "YES" ]; then
+    if [ "${DEPLOYMENT_LOCATION}" = "YES" ]; then
         BUILD_SCRIPTS_DIR="${SDKROOT}${WK_ALTERNATE_WEBKIT_SDK_PATH}${WK_LIBRARY_HEADERS_FOLDER_PATH}/wtf/Scripts"
     else
         BUILD_SCRIPTS_DIR="${BUILT_PRODUCTS_DIR}${WK_LIBRARY_HEADERS_FOLDER_PATH}/wtf/Scripts"
