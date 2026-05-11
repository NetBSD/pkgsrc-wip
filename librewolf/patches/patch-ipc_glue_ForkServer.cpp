$NetBSD$

--- ipc/glue/ForkServer.cpp.orig	2026-05-08 19:59:09.495174425 +0000
+++ ipc/glue/ForkServer.cpp
@@ -22,6 +22,7 @@
 #include <string.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <signal.h>
 
 #if defined(XP_LINUX) && defined(MOZ_SANDBOX)
 #  include "mozilla/SandboxLaunch.h"
