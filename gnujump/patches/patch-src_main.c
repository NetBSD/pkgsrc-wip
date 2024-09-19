$NetBSD$

--- src/main.c.orig	2008-09-23 14:17:29.000000000 +0000
+++ src/main.c
@@ -18,6 +18,7 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <locale.h>
 #include "gnujump.h"
 
 #include "setup.h"
