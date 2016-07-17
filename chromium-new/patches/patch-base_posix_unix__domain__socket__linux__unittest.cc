$NetBSD$

--- base/posix/unix_domain_socket_linux_unittest.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/posix/unix_domain_socket_linux_unittest.cc
@@ -2,10 +2,15 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include <stddef.h>
 #include <stdint.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
