$NetBSD$

Disable linux-user and bsd-user

--- qemu_mode/build_qemu_support.sh.orig	2017-05-31 22:53:05.000000000 +0000
+++ qemu_mode/build_qemu_support.sh
@@ -6,12 +6,11 @@
 cd qemu
 
 CFLAGS="-O3" ./configure --disable-werror \
-  --enable-system --enable-linux-user \
+  --enable-system --disable-linux-user --disable-bsd-user \
   --enable-guest-base --disable-gtk --disable-sdl --disable-vnc \
-  --target-list="x86_64-linux-user x86_64-softmmu arm-softmmu aarch64-softmmu"
+  --target-list="x86_64-softmmu arm-softmmu aarch64-softmmu"
 
 make
-cp -f "x86_64-linux-user/qemu-x86_64" "../../afl-qemu-trace"
 cp -f "x86_64-softmmu/qemu-system-x86_64" "../../afl-qemu-system-trace"
 cp -f "x86_64-softmmu/qemu-system-x86_64" "../../qemu-system-x86_64"
 cp -f "arm-softmmu/qemu-system-arm" "../../qemu-system-arm"
