--- asn.h.orig	2014-01-29 08:21:13.000000000 +0200
+++ asn.h	2014-04-25 11:10:23.000000000 +0300
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
+void ii_parse(char *arg);
 
 #endif
+#endif
