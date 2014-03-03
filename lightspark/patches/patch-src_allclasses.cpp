$NetBSD: patch-src_allclasses.cpp,v 1.1 2014/03/03 08:12:25 nsloss Exp $

Fix for building with clang otherwise a template of ASObject is created after it is insantiated.

--- src/allclasses.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/allclasses.cpp
@@ -17,6 +17,8 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/
 
+#define ALLCLASSES_CPP
+
 #include "scripting/toplevel/ASString.h"
 #include "scripting/toplevel/Date.h"
 #include "scripting/toplevel/Math.h"
@@ -87,3 +89,5 @@ CLASS_LAST
 
 //Define a variable to let outside code know the number of defined classes
 uint32_t asClassCount = CLASS_LAST;
+
+#undef ALLCLASSES_CPP
