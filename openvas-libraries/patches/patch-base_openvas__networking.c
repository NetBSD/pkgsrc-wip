$NetBSD$

Add NetBSD support.

--- base/openvas_networking.c.orig	2016-04-22 13:45:43.000000000 +0000
+++ base/openvas_networking.c
@@ -44,7 +44,7 @@ char global_source_iface[IFNAMSIZ] = { '
 struct in_addr global_source_addr = { .s_addr = 0 };
 
 /* Source IPv6 address. */
-struct in6_addr global_source_addr6 = { .s6_addr32 = { 0, 0, 0, 0 } };
+struct in6_addr global_source_addr6 = {};
 
  /* Source Interface/Address related functions. */
 
@@ -227,13 +227,23 @@ openvas_source_addr6_str (void)
 void
 ipv4_as_ipv6 (const struct in_addr *ip4, struct in6_addr *ip6)
 {
+#if defined(__NetBSD__)
+  size_t i;
+#endif
+
   if (ip4 == NULL || ip6 == NULL)
     return;
 
+#if defined(__NetBSD__)
+  for (i = 0; i < 12; i++)
+    ip6->s6_addr[i] = 0;
+  memcpy (&ip6->s6_addr[12], ip4, sizeof (struct in_addr));
+#else
   ip6->s6_addr32[0] = 0;
   ip6->s6_addr32[1] = 0;
   ip6->s6_addr32[2] = htonl (0xffff);
   memcpy (&ip6->s6_addr32[3], ip4, sizeof (struct in_addr));
+#endif
 }
 
 char *
@@ -246,7 +256,11 @@ addr6_as_str (const struct in6_addr *add
 
   str = g_malloc0 (INET6_ADDRSTRLEN);
   if (IN6_IS_ADDR_V4MAPPED (addr6))
+#if defined(__NetBSD__)
+    inet_ntop (AF_INET, &addr6->s6_addr[12], str, INET6_ADDRSTRLEN);
+#else
     inet_ntop (AF_INET, &addr6->s6_addr32[3], str, INET6_ADDRSTRLEN);
+#endif
   else
     inet_ntop (AF_INET6, addr6, str, INET6_ADDRSTRLEN);
   return str;
