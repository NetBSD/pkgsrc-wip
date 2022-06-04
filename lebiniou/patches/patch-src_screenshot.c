$NetBSD$

Will be fixed in 3.67.0.

--- src/screenshot.c.orig	2022-03-19 23:06:55.000000000 +0000
+++ src/screenshot.c
@@ -17,7 +17,7 @@
  *  along with lebiniou. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <wand/magick_wand.h>
+#include <MagickWand/MagickWand.h>
 #include "context.h"
 
 #define DIRECTORY      "/screenshots/"
