$NetBSD: patch-extended_ipinfo_support__asn.h,v 1.2 2013/07/06 16:28:36 yvs4sf Exp $

extended ipinfo support (asn.h part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN asn.h.orig asn.h
--- asn.h.orig	2013-07-06 08:38:48.000000000 +0300
+++ asn.h	2013-07-06 18:37:36.000000000 +0300
@@ -16,6 +16,9 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
+#ifndef ASN_H
+#define ASN_H
+
 // The autoconf system provides us with the NO_IPINFO define. 
 // Littering the code with #ifndef NO_IPINFO (double negative)
 // does not benefit readabilty. So here we invert the sense of the
@@ -27,15 +30,17 @@
 #ifndef NO_IPINFO
 #define IPINFO
 
-
-extern int ipinfo_no;
+#define II_ITEM_MAX	15
+#define ipinfo_no	ipinfo_nos[0]
+extern int ipinfo_nos[];
 extern int ipinfo_max;
-extern int iiwidth_len;
 extern int iihash;
 void asn_open();
 void asn_close();
 char *fmt_ipinfo(ip_t *addr);
 int get_iiwidth(void);
 int is_printii(void);
+void parse_iiarg(char *arg);
 
-#endif
+#endif	// NO_IPINFO
+#endif	// ASN_H
