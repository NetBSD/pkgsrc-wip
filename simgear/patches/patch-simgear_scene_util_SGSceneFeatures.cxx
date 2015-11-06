$NetBSD$

osg 3.4 compatibility changes

--- simgear/scene/util/SGSceneFeatures.cxx.orig	2015-02-18 20:10:39.000000000 +0000
+++ simgear/scene/util/SGSceneFeatures.cxx
@@ -25,10 +25,7 @@
 
 #include "SGSceneFeatures.hxx"
 
-#include <osg/FragmentProgram>
-#include <osg/VertexProgram>
-#include <osg/Point>
-#include <osg/PointSprite>
+#include <osg/GLExtensions>
 #include <osg/Texture>
 
 #include <OpenThreads/Mutex>
@@ -84,17 +81,17 @@ SGSceneFeatures::setTextureCompression(o
 bool
 SGSceneFeatures::getHavePointSprites(unsigned contextId) const
 {
-  return osg::PointSprite::isPointSpriteSupported(contextId);
+  return osg::GLExtensions::Get(contextId, true)->isPointSpriteSupported;
 }
 
 bool
 SGSceneFeatures::getHaveFragmentPrograms(unsigned contextId) const
 {
-  const osg::FragmentProgram::Extensions* fpe;
-  fpe = osg::FragmentProgram::getExtensions(contextId, true);
+  const osg::GLExtensions* fpe;
+  fpe = osg::GLExtensions::Get(contextId, true);
   if (!fpe)
     return false;
-  if (!fpe->isFragmentProgramSupported())
+  if (!fpe->isFragmentProgramSupported)
     return false;
   
   return true;
@@ -103,11 +100,11 @@ SGSceneFeatures::getHaveFragmentPrograms
 bool
 SGSceneFeatures::getHaveVertexPrograms(unsigned contextId) const
 {
-  const osg::VertexProgram::Extensions* vpe;
-  vpe = osg::VertexProgram::getExtensions(contextId, true);
+  const osg::GLExtensions* vpe;
+  vpe = osg::GLExtensions::Get(contextId, true);
   if (!vpe)
     return false;
-  if (!vpe->isVertexProgramSupported())
+  if (!vpe->isVertexProgramSupported)
     return false;
   
   return true;
@@ -124,11 +121,11 @@ SGSceneFeatures::getHaveShaderPrograms(u
 bool
 SGSceneFeatures::getHavePointParameters(unsigned contextId) const
 {
-  const osg::Point::Extensions* pe;
-  pe = osg::Point::getExtensions(contextId, true);
+  const osg::GLExtensions* pe;
+  pe = osg::GLExtensions::Get(contextId, true);
   if (!pe)
     return false;
-  if (!pe->isPointParametersSupported())
+  if (!pe->isPointParametersSupported)
     return false;
   return true;
 }
