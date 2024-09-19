$NetBSD$

Don't overwrite _*_SOURCE, it breaks build on NetBSD.

--- src/manage_sqlite3.c.orig	2016-08-25 12:15:47.000000000 +0000
+++ src/manage_sqlite3.c
@@ -23,7 +23,9 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#if !defined(__NetBSD__)
 #define _XOPEN_SOURCE /* Glibc2 needs this for strptime. */
+#endif
 
 #include "sql.h"
 #include "manage.h"
