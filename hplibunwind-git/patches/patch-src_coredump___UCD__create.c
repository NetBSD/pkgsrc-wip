$NetBSD$

--- src/coredump/_UCD_create.c.orig	2018-09-04 09:38:02.000000000 +0000
+++ src/coredump/_UCD_create.c
@@ -61,7 +61,9 @@ WITH THE SOFTWARE OR THE USE OR OTHER DE
 #endif
 
 #include <elf.h>
+#ifdef HAVE_SYS_PROCFS_H
 #include <sys/procfs.h> /* struct elf_prstatus */
+#endif
 
 #include "_UCD_lib.h"
 #include "_UCD_internal.h"
