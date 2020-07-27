$NetBSD$

--- device/gamepad/hid_writer_linux.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
