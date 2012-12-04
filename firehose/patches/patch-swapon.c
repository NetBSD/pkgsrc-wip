$NetBSD: patch-swapon.c,v 1.1 2012/12/04 01:29:39 othyro Exp $

Include <uvm/uvm_page.h> if MACHINE_ARCH = x86_64, and needs printf and exit.

--- swapon.c.orig	2003-10-14 07:54:07.000000000 +0000
+++ swapon.c
@@ -1,5 +1,11 @@
 #include <unistd.h>
+#include <stdio.h>
+#include <stdlib.h>
+#if defined(__x86_64__)
+#include <uvm/uvm_page.h>
+#else
 #include <asm/page.h>
+#endif
 #include <sys/swap.h>
 
 
@@ -12,7 +18,7 @@ int main(int argc, char *argv[])
 	}
 
 	printf("Enabling swap space on %s\n", argv[1]);
-	int result = swapon(argv[1], 0);
+	int result = swapon(argv[1]);
 	if(result)
 	{
 		perror("swapon");
