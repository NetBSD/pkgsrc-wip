$NetBSD$

* Add pkgsrc's lib names and path to found system libraries

--- configure-system-libraries.sh.orig	2024-11-08 09:36:26.467059850 +0000
+++ configure-system-libraries.sh
@@ -25,7 +25,7 @@ patch_config()
 			for LIB in ${SEARCH}; do
 				if [ -f "${DIR}/${LIB}" ]; then
 					echo "${LIB}"
-					sed "s|target=\"${REPLACE}\"|target=\"${DIR}/${LIB}\"|" "${CONFIG}" > "${CONFIG}.temp"
+					sed "s|target=\"${REPLACE}\"|target=\"${LIB}\"|" "${CONFIG}" > "${CONFIG}.temp"
 					mv "${CONFIG}.temp" "${CONFIG}"
 					return 0
 				fi
@@ -68,9 +68,9 @@ if [ "$(uname -s)" = "Darwin" ]; then
 	patch_config OpenAL "${SEARCHDIRS}" bin/OpenAL-CS.dll.config soft_oal.dylib libopenal.1.dylib
 	patch_config FreeType "${SEARCHDIRS}" bin/OpenRA.Platforms.Default.dll.config freetype6.dylib libfreetype.6.dylib
 else
-	SEARCHDIRS="/lib /lib64 /usr/lib /usr/lib64 /usr/lib/x86_64-linux-gnu /usr/lib/i386-linux-gnu /usr/lib/arm-linux-gnueabihf /usr/lib/aarch64-linux-gnu /usr/lib/powerpc64le-linux-gnu /usr/lib/mipsel-linux-gnu /usr/local/lib /opt/lib /opt/local/lib /app/lib"
-	patch_config "Lua 5.1" "${SEARCHDIRS}" bin/Eluant.dll.config lua51.so "liblua.so.5.1.5 liblua5.1.so.5.1 liblua5.1.so.0 liblua.so.5.1 liblua-5.1.so liblua5.1.so"
-	patch_config SDL2 "${SEARCHDIRS}" bin/SDL2-CS.dll.config SDL2.so "libSDL2-2.0.so.0 libSDL2-2.0.so libSDL2.so"
+	SEARCHDIRS="/lib /lib64 /usr/lib /usr/pkg/lib /usr/lib64 /usr/lib/x86_64-linux-gnu /usr/lib/i386-linux-gnu /usr/lib/arm-linux-gnueabihf /usr/lib/aarch64-linux-gnu /usr/lib/powerpc64le-linux-gnu /usr/lib/mipsel-linux-gnu /usr/local/lib /opt/lib /opt/local/lib /app/lib"
+	patch_config "Lua 5.1" "${SEARCHDIRS}" bin/Eluant.dll.config lua51.so "liblua5.1.la liblua.so.5.1.5 liblua5.1.so.5.1 liblua5.1.so.0 liblua.so.5.1 liblua-5.1.so liblua5.1.so"
+	patch_config SDL2 "${SEARCHDIRS}" bin/SDL2-CS.dll.config SDL2.so "libSDL2.la libSDL2-2.0.so.0 libSDL2-2.0.so libSDL2.so"
 	patch_config OpenAL "${SEARCHDIRS}" bin/OpenAL-CS.dll.config soft_oal.so "libopenal.so.1 libopenal.so"
 	patch_config FreeType "${SEARCHDIRS}" bin/OpenRA.Platforms.Default.dll.config freetype6.so "libfreetype.so.6 libfreetype.so"
 fi
