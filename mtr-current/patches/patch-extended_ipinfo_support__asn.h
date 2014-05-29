--- asn.h.orig	2014-05-29 12:31:51.000000000 +0300
+++ asn.h	2014-05-19 16:20:01.000000000 +0300
@@ -16,6 +16,9 @@
     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
+#ifndef ASN_H
+#define ASN_H
+
 // The autoconf system provides us with the NO_IPINFO define. 
 // Littering the code with #ifndef NO_IPINFO (double negative)
 // does not benefit readabilty. So here we invert the sense of the
@@ -27,15 +30,12 @@
 #ifndef NO_IPINFO
 #define IPINFO
 
-
-extern int ipinfo_no;
-extern int ipinfo_max;
-extern int iiwidth_len;
-extern int iihash;
-void asn_open();
+extern int enable_ipinfo;
 void asn_close();
 char *fmt_ipinfo(ip_t *addr);
-int get_iiwidth(void);
-int is_printii(void);
+void ii_parsearg(char *arg);
+void ii_action(int action_asn);
+int ii_getwidth(void);
 
 #endif
+#endif
