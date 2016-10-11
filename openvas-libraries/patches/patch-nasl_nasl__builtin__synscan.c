$NetBSD$

--- nasl/nasl_builtin_synscan.c.orig	2015-08-03 10:14:31.000000000 +0000
+++ nasl/nasl_builtin_synscan.c
@@ -692,7 +692,11 @@ scan (struct arglist * env, char* hostna
   if (IN6_IS_ADDR_V4MAPPED (dst6))
     {
       family = AF_INET;
+#if defined(__NetBSD__)
+      memcpy(&dst.s_addr, &dst6->s6_addr[12], 4);
+#else
       dst.s_addr = dst6->s6_addr32[3];
+#endif
       soc = rawsocket (AF_INET);
     }
   else
@@ -797,7 +801,11 @@ plugin_run_synscan (lex_ctxt * lexic)
   struct timeval  tv;
 #endif
 
+#if defined(__NetBSD__)
+  memcpy(&inaddr.s_addr, &dst6->s6_addr[12], 4);
+#else
   inaddr.s_addr = dst6->s6_addr32[3];
+#endif
   dst = &inaddr;
 
   if (islocalhost (dst))
