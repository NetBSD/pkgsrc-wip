$NetBSD$

--- qemu_mode/build_qemu_support.sh.orig	2016-10-19 19:08:17.000000000 +0000
+++ qemu_mode/build_qemu_support.sh
@@ -7,10 +7,10 @@ CPU_TARGET=x86_64
 cd qemu
 
 CFLAGS="-O3" ./configure --disable-werror \
-  --enable-system --enable-linux-user \
+  --enable-system --enable-bsd-user \
   --enable-guest-base --disable-gtk --disable-sdl --disable-vnc \
-  --target-list="${CPU_TARGET}-linux-user ${CPU_TARGET}-softmmu"
+  --target-list="${CPU_TARGET}-bsd-user ${CPU_TARGET}-softmmu"
 
 make
-cp -f "${CPU_TARGET}-linux-user/qemu-${CPU_TARGET}" "../../afl-qemu-trace"
+cp -f "${CPU_TARGET}-bsd-user/qemu-${CPU_TARGET}" "../../afl-qemu-trace"
 cp -f "${CPU_TARGET}-softmmu/qemu-system-${CPU_TARGET}" "../../afl-qemu-system-trace"
