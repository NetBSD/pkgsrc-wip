$NetBSD$

--- gcc/config/netbsd.h.orig	2017-07-09 04:22:43.000000000 +0000
+++ gcc/config/netbsd.h
@@ -17,6 +17,9 @@ You should have received a copy of the G
 along with GCC; see the file COPYING3.  If not see
 <http://www.gnu.org/licenses/>.  */
 
+
+#include "netbsd-protos.h"
+
 /* TARGET_OS_CPP_BUILTINS() common to all NetBSD targets.  */
 #define NETBSD_OS_CPP_BUILTINS_COMMON()		\
   do						\
@@ -164,3 +167,9 @@ along with GCC; see the file COPYING3.  
 
 #undef WINT_TYPE
 #define WINT_TYPE "int"
+
+#undef SUBTARGET_INIT_BUILTINS
+#define SUBTARGET_INIT_BUILTINS			\
+do {						\
+  netbsd_patch_builtins ();			\
+} while(0)
