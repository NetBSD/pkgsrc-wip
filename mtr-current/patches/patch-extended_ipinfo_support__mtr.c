$NetBSD: patch-extended_ipinfo_support__mtr.c,v 1.3 2013/10/25 11:50:20 yvs4sf Exp $

extended ipinfo support (mtr.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN mtr.c.orig mtr.c
--- mtr.c.orig	2013-07-06 18:32:34.000000000 +0300
+++ mtr.c	2013-07-06 18:49:49.000000000 +0300
@@ -289,8 +288,8 @@
     { "inet", 0, 0, '4' },	/* IPv4 only */
     { "inet6", 0, 0, '6' },	/* IPv6 only */
 #ifdef IPINFO
-    { "ipinfo", 1, 0, 'y' },    /* IP info lookup */
-    { "aslookup", 0, 0, 'z' },  /* Do AS lookup (--ipinfo 0) */
+    { "ipinfo", 1, 0, 'y' },    /* Do ipinfo lookup */
+    { "aslookup", 0, 0, 'z' },  /* Do AS lookup */
 #endif
     { 0, 0, 0, 0 }
   };
@@ -456,12 +463,12 @@
 #endif
 #ifdef IPINFO
     case 'y':
-      ipinfo_no = atoi (optarg);
+      parse_iiarg(optarg);
       if (ipinfo_no < 0)
         ipinfo_no = 0;
       break;
     case 'z':
-      ipinfo_no = 0;
+      parse_iiarg("-1,0"); // routeviews.org origin
       break;
 #else
     case 'y':
@@ -575,7 +582,7 @@
            "\t\t[--csv|-C] [--raw] [--xml] [--split] [--mpls] [--no-dns] [--show-ips]\n"
            "\t\t[--address interface] [--filename=FILE|-F]\n" /* BL */
 #ifdef IPINFO
-           "\t\t[--ipinfo=item_no|-y item_no]\n"
+           "\t\t[--ipinfo=[-orig,]no[,no...] | -y [-orig,]no[,no...] ]\n"
            "\t\t[--aslookup|-z]\n"
 #endif
            "\t\t[--psize=bytes/-s bytes] [--order fields]\n"            /* ok */
