--- mtr.c.orig	2014-05-29 12:31:51.000000000 +0300
+++ mtr.c	2014-05-29 14:21:02.000000000 +0300
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
@@ -458,17 +458,15 @@
 #endif
 #ifdef IPINFO
     case 'y':
-      ipinfo_no = atoi (optarg);
-      if (ipinfo_no < 0)
-        ipinfo_no = 0;
+      ii_parsearg(optarg);
       break;
     case 'z':
-      ipinfo_no = 0;
+      ii_parsearg("2");	// routeviews.org origin
       break;
 #else
     case 'y':
     case 'z':
-      fprintf( stderr, "IPINFO not enabled.\n" );
+      fprintf(stderr, "IPINFO not enabled.\n");
       break;
 #endif
     }
@@ -577,8 +575,7 @@
            "\t\t[--csv|-C] [--raw] [--xml] [--split] [--mpls] [--no-dns] [--show-ips]\n"
            "\t\t[--address interface] [--filename=FILE|-F]\n" /* BL */
 #ifdef IPINFO
-           "\t\t[--ipinfo=item_no|-y item_no]\n"
-           "\t\t[--aslookup|-z]\n"
+           "\t\t[--aslookup|-z] [--ipinfo|-y origin,fields]\n"
 #endif
            "\t\t[--psize=bytes/-s bytes] [--order fields]\n"            /* ok */
            "\t\t[--report-wide|-w] [--inet] [--inet6] [--max-ttl=NUM] [--first-ttl=NUM]\n"
