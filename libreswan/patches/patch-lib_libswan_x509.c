--- lib/libswan/x509dn.c.dist	2023-08-06 15:38:41.229683426 +0000
+++ lib/libswan/x509dn.c	2023-08-06 15:39:26.829938849 +0000
@@ -777,7 +777,9 @@
 			       /* XXX: where did '/' come from? */
 			       src[0] != '/') {
 				/* assume nul termination */
-				if (src[0] == '\\' && isxdigit(src[1]) && isxdigit(src[2])) {
+				if (src[0] == '\\' &&
+				    char_isxdigit(src[1]) &&
+				    char_isxdigit(src[2])) {
 					char hex[3] = { src[1], src[2], };
 					uint8_t byte = strtol(hex, NULL, 16);
 					EXTEND_OBJ(&byte, 1);
