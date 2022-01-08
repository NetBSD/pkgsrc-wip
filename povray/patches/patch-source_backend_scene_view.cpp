$NetBSD$

Work around a deprecated boost header.

--- source/backend/scene/view.cpp.orig	2021-07-08 09:56:01.000000000 +0000
+++ source/backend/scene/view.cpp
@@ -31,7 +31,7 @@
 
 #include <boost/thread.hpp>
 #include <boost/bind.hpp>
-#include <boost/math/common_factor.hpp>
+#include <boost/integer/common_factor_rt.hpp>
 
 // frame.h must always be the first POV file included (pulls in platform config)
 #include "backend/frame.h"
@@ -798,7 +798,7 @@ void View::StartRender(POVMS_Object& ren
 		viewData.renderBlockStep %= (viewData.blockWidth*viewData.blockHeight);
 		if (!viewData.renderBlockStep)
 			viewData.renderBlockStep = (viewData.blockWidth*viewData.blockHeight);
-		while(boost::math::gcd((long)viewData.renderBlockStep,(long)(viewData.blockWidth*viewData.blockHeight))>1)
+		while(boost::integer::gcd((long)viewData.renderBlockStep,(long)(viewData.blockWidth*viewData.blockHeight))>1)
 			viewData.renderBlockStep--;
 	}
 
