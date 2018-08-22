$NetBSD$

Inlcude missing system header file.

--- clientlib.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ clientlib.c
@@ -30,6 +30,7 @@ static char XRNrcsid[] = "$Id: clientlib
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdlib.h>
 #include "config.h"
 #include "utils.h"
 #include <X11/Xos.h>
