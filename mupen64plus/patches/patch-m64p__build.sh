$NetBSD: patch-m64p__build.sh,v 1.2 2012/04/20 19:41:03 othyro Exp $

Correctly move library and symbolic link.

--- m64p_build.sh.orig	2011-07-09 18:29:36.000000000 +0000
+++ m64p_build.sh
@@ -32,8 +32,7 @@ fi
 echo "************************************ Building core library"
 "$MAKE" -C source/mupen64plus-core/projects/unix clean
 "$MAKE" -C source/mupen64plus-core/projects/unix all $@
-cp source/mupen64plus-core/projects/unix/libmupen64plus.so.2.* ./test/
-mv source/mupen64plus-core/projects/unix/libmupen64plus.so.2 ./test/
+cp -P source/mupen64plus-core/projects/unix/libmupen64plus.so.2* ./test/
 cp source/mupen64plus-core/data/* ./test/
 gunzip --stdout source/mupen64plus-core/roms/m64p_test_rom.v64.gz > ./test/m64p_test_rom.v64
 
