$NetBSD$

--- idlib/math/Simd_AVX.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/math/Simd_AVX.h
@@ -23,17 +23,11 @@
 ===============================================================================
 */
 
-#ifdef __linux__
 #define ALLOW_AVX __attribute__ ((__target__ ("avx")))
-#else
-#define ALLOW_AVX
-#endif
-
-
 
 class idSIMD_AVX : public idSIMD_SSE3 {
 public:
 	virtual const char * VPCALL GetName( void ) const;
 	virtual void VPCALL CullByFrustum( idDrawVert *verts, const int numVerts, const idPlane frustum[6], byte *pointCull, float epsilon ) ALLOW_AVX;
 	virtual void VPCALL CullByFrustum2( idDrawVert *verts, const int numVerts, const idPlane frustum[6], unsigned short *pointCull, float epsilon ) ALLOW_AVX;
-};
\ No newline at end of file
+};
