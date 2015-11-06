$NetBSD$

osg 3.4 compatibility changes

--- simgear/scene/sky/CloudShaderGeometry.cxx.orig	2015-02-18 20:10:39.000000000 +0000
+++ simgear/scene/sky/CloudShaderGeometry.cxx
@@ -128,7 +128,7 @@ void CloudShaderGeometry::drawImplementa
         sortData.frameSorted = frameNumber;
     }
     
-    const Extensions* extensions = getExtensions(state.getContextID(),true);
+    const GLExtensions* extensions = GLExtensions::Get(state.getContextID(),true);
     GLfloat ua1[3] = { (GLfloat) alpha_factor,
                        (GLfloat) shade_factor,
                        (GLfloat) cloud_height };
