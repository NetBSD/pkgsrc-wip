$NetBSD$

--- idlib/bv/Frustum.cpp.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/bv/Frustum.cpp
@@ -2033,7 +2033,7 @@ bool idFrustum::ProjectionBounds( const 
 	return ProjectionBounds( idBox( bounds, vec3_origin, mat3_identity ), projectionBounds );
 }
 
-#if !defined(__linux__) && !defined(MACOS_X)
+#if !defined(unix) && !defined(__unix__) && !defined(__unix)
 
 /*
 ============
