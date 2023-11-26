$NetBSD$

Include cmath for abs, floor and pow (exposed by turning pre-compiled headers off).
Use numeric_limits for epsilon, which is the (portable) C++ way.

--- source/common/utility/palette.cpp.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/utility/palette.cpp
@@ -33,6 +33,8 @@
 */
 
 #include <algorithm>
+#include <cmath>
+#include <limits>
 #include "palutil.h"
 #include "palentry.h"
 #include "sc_man.h"
@@ -877,12 +879,12 @@ int AddSpecialColormap(PalEntry *BaseCol
 	for (unsigned i = 1; i < SpecialColormaps.Size(); i++)
 	{
 		// Avoid precision issues here when trying to find a proper match.
-		if (fabs(SpecialColormaps[i].ColorizeStart[0] - r1) < FLT_EPSILON &&
-			fabs(SpecialColormaps[i].ColorizeStart[1] - g1) < FLT_EPSILON &&
-			fabs(SpecialColormaps[i].ColorizeStart[2] - b1) < FLT_EPSILON &&
-			fabs(SpecialColormaps[i].ColorizeEnd[0] - r2) < FLT_EPSILON &&
-			fabs(SpecialColormaps[i].ColorizeEnd[1] - g2) < FLT_EPSILON &&
-			fabs(SpecialColormaps[i].ColorizeEnd[2] - b2) < FLT_EPSILON)
+		if (fabs(SpecialColormaps[i].ColorizeStart[0] - r1) < std::numeric_limits<float>::epsilon() &&
+			fabs(SpecialColormaps[i].ColorizeStart[1] - g1) < std::numeric_limits<float>::epsilon() &&
+			fabs(SpecialColormaps[i].ColorizeStart[2] - b1) < std::numeric_limits<float>::epsilon() &&
+			fabs(SpecialColormaps[i].ColorizeEnd[0] - r2) < std::numeric_limits<float>::epsilon() &&
+			fabs(SpecialColormaps[i].ColorizeEnd[1] - g2) < std::numeric_limits<float>::epsilon() &&
+			fabs(SpecialColormaps[i].ColorizeEnd[2] - b2) < std::numeric_limits<float>::epsilon())
 		{
 			return i;	// The map already exists
 		}
