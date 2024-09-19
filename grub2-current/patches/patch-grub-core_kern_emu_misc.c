$NetBSD: patch-grub-core_kern_emu_misc.c,v 1.1 2013/09/09 09:47:45 gregoire Exp $

Do not include error.h since it does not exist on NetBSD and
it is not needed on Linux.

--- grub-core/kern/emu/misc.c.orig	2013-09-09 09:39:11.000000000 +0000
+++ grub-core/kern/emu/misc.c
@@ -20,7 +20,6 @@
 #include <config.h>
 
 #include <errno.h>
-#include <error.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
