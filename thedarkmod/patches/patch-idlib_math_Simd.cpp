$NetBSD$

--- idlib/math/Simd.cpp.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/math/Simd.cpp
@@ -56,7 +56,7 @@ idSIMD::InitProcessor
 void idSIMD::InitProcessor( const char *module, bool forceGeneric ) {
 	idSIMDProcessor *newProcessor;
 
-	cpuid_t cpuid = idLib::sys->GetProcessorId();
+	id_cpuid_t cpuid = idLib::sys->GetProcessorId();
 
 	/*
 	* Tels: Bug #2413: Under Linux, cpuid_t is 0, so use inline assembly to get
@@ -103,7 +103,7 @@ void idSIMD::InitProcessor( const char *
 	}
 
 	//idLib::common->Printf( "cpuid result is %i (c = %i d = %i)\n", result, c, d);
-	cpuid = ( cpuid_t )result;
+	cpuid = ( id_cpuid_t )result;
 #endif
 
 	// Print what we found to console
@@ -3986,7 +3986,7 @@ void idSIMD::Test_f( const idCmdArgs &ar
 	p_generic = generic;
 
 	if ( idStr::Length( args.Argv( 1 ) ) != 0 ) {
-		cpuid_t cpuid = idLib::sys->GetProcessorId();
+		id_cpuid_t cpuid = idLib::sys->GetProcessorId();
 		idStr argString = args.Args();
 
 		argString.Remove( ' ' );
