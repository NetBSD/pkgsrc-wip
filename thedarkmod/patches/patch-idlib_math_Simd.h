$NetBSD$

--- idlib/math/Simd.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/math/Simd.h
@@ -91,7 +91,7 @@ class idSIMDProcessor {
 public:
 									idSIMDProcessor( void ) { cpuid = CPUID_NONE; }
 
-	cpuid_t							cpuid;
+	id_cpuid_t							cpuid;
 
 	virtual const char * VPCALL		GetName( void ) const = 0;
 
