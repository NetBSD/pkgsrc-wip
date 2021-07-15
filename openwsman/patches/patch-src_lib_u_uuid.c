$NetBSD$

Handle NetBSD like FreeBSD.

--- src/lib/u/uuid.c.orig	2019-09-17 09:38:38.000000000 +0000
+++ src/lib/u/uuid.c
@@ -141,7 +141,7 @@ generate_uuid(char *buf, int size, int b
 #include <sys/param.h>
 #include <netinet/in.h>
 
-#if defined(__APPLE__)  ||  defined(__FreeBSD__)
+#if defined(__APPLE__)  ||  defined(__FreeBSD__) || defined(__NetBSD__)
 #include <net/bpf.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
@@ -337,7 +337,7 @@ generate_uuid ( char* buf, 
     clock_sequence++;
 
     // get mac address
-#if defined(__APPLE__)  ||  defined(__FreeBSD__)
+#if defined(__APPLE__)  ||  defined(__FreeBSD__) || defined(__NetBSD__)
     if ( mac_address( mac, 6 ) == 0 )
 #else    
     if (mac_addr_sys(mac) == 0 )
