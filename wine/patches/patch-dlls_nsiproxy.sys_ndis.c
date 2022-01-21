$NetBSD$

Fix errors due to {if,sdl}_type definition in net/if_dl.h.

--- dlls/nsiproxy.sys/ndis.c.orig	2022-01-21 20:02:16.886853181 +0000
+++ dlls/nsiproxy.sys/ndis.c
@@ -32,6 +32,9 @@
 
 #ifdef HAVE_NET_IF_H
 #include <net/if.h>
+#if defined(__NetBSD__)
+#undef if_type
+#endif
 #endif
 
 #ifdef HAVE_NET_IF_ARP_H
@@ -56,6 +59,9 @@
 
 #ifdef HAVE_NET_IF_DL_H
 #include <net/if_dl.h>
+#if defined(__NetBSD__)
+#undef sdl_type
+#endif
 #endif
 
 #ifdef HAVE_NET_IF_TYPES_H
@@ -225,7 +231,11 @@ static NTSTATUS if_get_physical( const c
             continue;
 
         for (i = 0; i < ARRAY_SIZE(types); i++)
+#if defined(__NetBSD__)
+            if (sdl->sdl_addr.dl_type == types[i].sdl_type)
+#else
             if (sdl->sdl_type == types[i].sdl_type)
+#endif
             {
                 *type = types[i].mib_type;
                 break;
