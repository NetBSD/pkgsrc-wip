$NetBSD$

Fix man installation path.

--- CMakeScripts/Pod2man.cmake.orig	2018-12-31 23:36:02.000000000 +0900
+++ CMakeScripts/Pod2man.cmake	2019-01-03 10:09:57.981296072 +0900
@@ -28,12 +28,12 @@ macro(pod2man PODFILE_FULL RELEASE SECTI
             set(MANPAGE_TARGET "man-${NAME}-${LANG}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/${LANG}/man${SECTION}")
+            set(MANFILE_DEST "${SHARE_INSTALL_MANDIR}/man/${LANG}/man${SECTION}")
         else()
             set(MANPAGE_TARGET "man-${NAME}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/man${SECTION}")
+            set(MANFILE_DEST "${SHARE_INSTALL_MANDIR}/man/man${SECTION}")
         endif()
         add_custom_command(
             OUTPUT ${MANFILE_TEMP}
