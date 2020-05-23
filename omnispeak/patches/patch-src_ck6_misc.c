$NetBSD$

Part of a patch set to search for data files in PREFIX.

--- src/ck6_misc.c.orig	2020-05-04 04:33:47.000000000 +0000
+++ src/ck6_misc.c
@@ -17,6 +17,7 @@ along with this program; if not, write t
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
+#include <limits.h>
 #include <stdio.h>
 #include "id_ca.h"
 #include "id_in.h"
@@ -117,7 +118,7 @@ bool CK6_IsPresent()
 	if (!CA_IsFilePresent("AUDIO.CK6"))
 		return false;
 
-	char egaGraphName[] = "EGAGRAPH.CK6";
+	char egaGraphName[PATH_MAX] = "EGAGRAPH.CK6";
 	CAL_AdjustFilenameCase(egaGraphName);
 	size_t egaGraphSize = CA_GetFileSize(egaGraphName);
 	if (egaGraphSize == 464662)
