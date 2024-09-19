$NetBSD$

--- include/tdep-x86_64/jmpbuf.h.orig	2018-09-04 09:38:02.000000000 +0000
+++ include/tdep-x86_64/jmpbuf.h
@@ -40,4 +40,11 @@ WITH THE SOFTWARE OR THE USE OR OTHER DE
 #define JB_MASK_SAVED   0
 #define JB_MASK         9
 
+#elif defined __NetBSD__
+
+#define JB_SP           6
+#define JB_RP           7
+#define JB_MASK_SAVED   8
+#define JB_MASK         9
+
 #endif
