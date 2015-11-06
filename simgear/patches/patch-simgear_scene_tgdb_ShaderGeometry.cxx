$NetBSD$

osg 3.4 compatibility changes

--- simgear/scene/tgdb/ShaderGeometry.cxx.orig	2015-02-18 20:10:39.000000000 +0000
+++ simgear/scene/tgdb/ShaderGeometry.cxx
@@ -47,7 +47,7 @@ void ShaderGeometry::addObject(const Vec
 void ShaderGeometry::drawImplementation(osg::RenderInfo& renderInfo) const
 {
     State& state = *renderInfo.getState();
-    const Extensions* extensions = getExtensions(state.getContextID(), true);
+    const GLExtensions* extensions = GLExtensions::Get(state.getContextID(), true);
     Vec4Array::const_iterator citer = _posScaleArray->begin();
     Vec4Array::const_iterator cend = _posScaleArray->end();
     FloatArray::const_iterator viter = _vertexAttribArray->begin();
