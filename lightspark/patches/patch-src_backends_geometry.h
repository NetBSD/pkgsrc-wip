$NetBSD: patch-src_backends_geometry.h,v 1.1 2014/02/22 12:17:46 thomasklausner Exp $

C++ does not allow > > except as operator.

--- src/backends/geometry.h.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/backends/geometry.h
@@ -85,7 +85,7 @@ public:
 	GeomToken(GEOM_TOKEN_TYPE _t, const MATRIX _m):fillStyle(0xff),lineStyle(0xff),textureTransform(_m),type(_t),p1(0,0),p2(0,0),p3(0,0){}
 };
 
-typedef std::vector<GeomToken, reporter_allocator<GeomToken>> tokensVector;
+typedef std::vector<GeomToken, reporter_allocator<GeomToken> > tokensVector;
 
 enum SHAPE_PATH_SEGMENT_TYPE { PATH_START=0, PATH_STRAIGHT, PATH_CURVE_QUADRATIC };
 
