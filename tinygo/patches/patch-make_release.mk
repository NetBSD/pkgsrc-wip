$NetBSD$

- fix PLIST issue with macOS cp(1)

--- make/release.mk.orig	2026-09-15 12:30:58.952194373 +0000
+++ make/release.mk
@@ -76,7 +76,7 @@ endif
 	@cp -rp lib/mingw-w64/mingw-w64-crt/math/x86                    build/release/tinygo/lib/mingw-w64/mingw-w64-crt/math
 	@cp -rp lib/mingw-w64/mingw-w64-crt/misc                        build/release/tinygo/lib/mingw-w64/mingw-w64-crt
 	@cp -rp lib/mingw-w64/mingw-w64-crt/stdio                       build/release/tinygo/lib/mingw-w64/mingw-w64-crt
-	@cp -rp lib/mingw-w64/mingw-w64-headers/crt/                    build/release/tinygo/lib/mingw-w64/mingw-w64-headers
+	@cp -rp lib/mingw-w64/mingw-w64-headers/crt                    build/release/tinygo/lib/mingw-w64/mingw-w64-headers
 	@cp -rp lib/mingw-w64/mingw-w64-headers/defaults/include        build/release/tinygo/lib/mingw-w64/mingw-w64-headers/defaults
 	@cp -rp lib/mingw-w64/mingw-w64-headers/include                 build/release/tinygo/lib/mingw-w64/mingw-w64-headers
 	@cp -rp lib/nrfx/*                   build/release/tinygo/lib/nrfx
