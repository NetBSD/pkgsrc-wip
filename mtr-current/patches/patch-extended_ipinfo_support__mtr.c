$NetBSD: patch-extended_ipinfo_support__mtr.c,v 1.1 2013/06/20 07:25:59 yvs4sf Exp $

extended ipinfo support (mtr.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN mtr.c.orig mtr.c
--- mtr.c.orig	2013-05-15 12:11:37.000000000 +0300
+++ mtr.c	2013-05-15 12:27:09.000000000 +0300
@@ -290,8 +290,8 @@
     { "inet", 0, 0, '4' },	/* IPv4 only */
     { "inet6", 0, 0, '6' },	/* IPv6 only */
 #ifndef NO_IPINFO
-    { "ipinfo", 1, 0, 'y' },    /* IP info lookup */
-    { "aslookup", 0, 0, 'z' },  /* Do AS lookup (--ipinfo 0) */
+    { "ipinfo", 1, 0, 'y' },    /* Do ipinfo lookup */
+    { "aslookup", 0, 0, 'z' },  /* Do AS lookup */
 #endif
     { 0, 0, 0, 0 }
   };
@@ -457,12 +457,12 @@
 #endif
 #ifndef NO_IPINFO
     case 'y':
-      ipinfo_no = atoi (optarg);
-      if (ipinfo_no < 0)
-        ipinfo_no = 0;
+      parse_iiarg(optarg);
+      if (ipinfo_nos[0] < 0)
+        ipinfo_nos[0] = 0;
       break;
     case 'z':
-      ipinfo_no = 0;
+      parse_iiarg("-1,0"); // routeviews.org origin
       break;
 #endif
     }
@@ -571,7 +571,7 @@
            "\t\t[--csv|-C] [--raw] [--split] [--mpls] [--no-dns] [--show-ips]\n"
            "\t\t[--address interface] [--filename=FILE|-F]\n" /* BL */
 #ifndef NO_IPINFO
-           "\t\t[--ipinfo=item_no|-y item_no]\n"
+           "\t\t[--ipinfo=[-orig,]no[,no...] | -y [-orig,]no[,no...] ]\n"
            "\t\t[--aslookup|-z]\n"
 #endif
            "\t\t[--psize=bytes/-s bytes]\n"            /* ok */
