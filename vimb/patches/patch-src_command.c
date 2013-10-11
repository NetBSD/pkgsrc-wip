$NetBSD: patch-src_command.c,v 1.1 2013/10/11 16:46:47 leot1990 Exp $

<sys/wait.h> is needed for WIFEXITED and WEXITSTATUS macros.

--- src/command.c.orig	2013-07-27 08:25:34.000000000 +0000
+++ src/command.c
@@ -17,6 +17,8 @@
  * along with this program. If not, see http://www.gnu.org/licenses/.
  */
 
+#include <sys/wait.h>
+
 #include "main.h"
 #include "command.h"
 #include "keybind.h"
