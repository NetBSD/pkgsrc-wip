$NetBSD: patch-m64p__build.sh,v 1.1.1.1 2011/12/13 15:11:47 othyro Exp $

Correctly move library and symbolic link.

--- m64p_build.sh.orig	2011-12-13 14:21:25.000000000 +0000
+++ m64p_build.sh
@@ -28,8 +28,7 @@ mkdir -p test
 echo "************************************ Building core library"
 make -C source/mupen64plus-core/projects/unix clean
 make -C source/mupen64plus-core/projects/unix all $@
-cp source/mupen64plus-core/projects/unix/libmupen64plus.so.2.* ./test/
-mv source/mupen64plus-core/projects/unix/libmupen64plus.so.2 ./test/
+cp -P source/mupen64plus-core/projects/unix/libmupen64plus.so.2* ./test/
 cp source/mupen64plus-core/data/* ./test/
 gunzip --stdout source/mupen64plus-core/roms/mupen64plus.v64.gz > ./test/m64p_test_rom.v64
 
