$NetBSD$

Remove Linux-specific headers.
This is wrong, but allows the build to proceed further on NetBSD.

--- src/efi.c.orig	2024-02-07 18:08:09.765844437 +0000
+++ src/efi.c
@@ -37,11 +37,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
-#include <linux/sockios.h>
-#include <linux/types.h>
 #include <net/if.h>
-#include <asm/types.h>
-#include <linux/ethtool.h>
 #include "efi.h"
 #include "efibootmgr.h"
 #include "list.h"
