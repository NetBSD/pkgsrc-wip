$NetBSD: patch-extended_ipinfo_support__asn.h,v 1.1 2013/06/20 07:25:59 yvs4sf Exp $

extended ipinfo support (asn.h part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN asn.h.orig asn.h
--- asn.h.orig	2013-05-15 12:11:37.000000000 +0300
+++ asn.h	2013-05-15 14:54:18.000000000 +0300
@@ -16,13 +16,18 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
-extern int ipinfo_no;
+#ifndef ASN_H
+#define ASN_H
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
+#endif
 
