$NetBSD$

--- TypeInfo/main.cpp.orig	2019-02-02 17:51:39.000000000 +0000
+++ TypeInfo/main.cpp
@@ -221,7 +221,7 @@ void			idSysLocal::DebugVPrintf( const c
 
 double			idSysLocal::GetClockTicks( void ) { return 0.0; }
 double			idSysLocal::ClockTicksPerSecond( void ) { return 1.0; }
-cpuid_t			idSysLocal::GetProcessorId( void ) { return (cpuid_t)0; }
+id_cpuid_t		idSysLocal::GetProcessorId( void ) { return (cpuid_t)0; }
 const char *	idSysLocal::GetProcessorString( void ) { return ""; }
 void			idSysLocal::FPU_SetFTZ( bool enable ) {}
 void			idSysLocal::FPU_SetDAZ( bool enable ) {}
