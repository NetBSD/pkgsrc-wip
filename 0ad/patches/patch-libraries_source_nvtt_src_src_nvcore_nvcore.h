$NetBSD$

--- libraries/source/nvtt/src/src/nvcore/nvcore.h.orig	2015-07-21 15:53:21.000000000 +0000
+++ libraries/source/nvtt/src/src/nvcore/nvcore.h
@@ -41,6 +41,9 @@
 #elif defined POSH_OS_FREEBSD
 #	define NV_OS_FREEBSD 1
 #	define NV_OS_UNIX 1
+#elif defined POSH_OS_NETBSD
+#	define NV_OS_NETBSD 1
+#	define NV_OS_UNIX 1
 #elif defined POSH_OS_OPENBSD
 #	define NV_OS_OPENBSD 1
 #	define NV_OS_UNIX 1
@@ -187,7 +190,7 @@ typedef uint32      uint;
 #elif NV_CC_GNUC
 #	if NV_OS_LINUX
 #		include "DefsGnucLinux.h"
-#	elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_OPENBSD
+#	elif NV_OS_DARWIN || NV_OS_FREEBSD || NV_OS_NETBSD || NV_OS_OPENBSD
 #		include "DefsGnucDarwin.h"
 #	elif NV_OS_MINGW
 #		include "DefsGnucWin32.h"
