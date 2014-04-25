--- mtr.c.orig	2014-04-20 21:28:39.000000000 +0300
+++ mtr.c	2014-04-22 21:39:25.000000000 +0300
@@ -291,8 +291,8 @@
     { "inet", 0, 0, '4' },	/* IPv4 only */
     { "inet6", 0, 0, '6' },	/* IPv6 only */
 #ifdef IPINFO
-    { "ipinfo", 1, 0, 'y' },    /* IP info lookup */
-    { "aslookup", 0, 0, 'z' },  /* Do AS lookup (--ipinfo 0) */
+    { "ipinfo", 1, 0, 'y' },
+    { "aslookup", 0, 0, 'z' },
 #endif
     { 0, 0, 0, 0 }
   };
@@ -458,12 +458,12 @@
 #endif
 #ifdef IPINFO
     case 'y':
-      ipinfo_no = atoi (optarg);
+      ii_parse(optarg);
       if (ipinfo_no < 0)
         ipinfo_no = 0;
       break;
     case 'z':
-      ipinfo_no = 0;
+      ii_parse("2,1"); // routeviews.org origin
       break;
 #else
     case 'y':
@@ -577,7 +577,7 @@
            "\t\t[--csv|-C] [--raw] [--xml] [--split] [--mpls] [--no-dns] [--show-ips]\n"
            "\t\t[--address interface] [--filename=FILE|-F]\n" /* BL */
 #ifdef IPINFO
-           "\t\t[--ipinfo=item_no|-y item_no]\n"
+           "\t\t[--ipinfo|-y origin,fields]\n"
            "\t\t[--aslookup|-z]\n"
 #endif
            "\t\t[--psize=bytes/-s bytes] [--order fields]\n"            /* ok */
