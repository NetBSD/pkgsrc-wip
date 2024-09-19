$NetBSD$

--- sys/sys_public.h.orig	2019-02-02 17:51:38.000000000 +0000
+++ sys/sys_public.h
@@ -16,6 +16,9 @@
 #ifndef __SYS_PUBLIC__
 #define __SYS_PUBLIC__
 
+#include <stdarg.h>
+#include <stdlib.h>
+
 /*
 ===============================================================================
 
@@ -137,21 +140,18 @@
 #endif
 
 
-// Linux
-#ifdef __linux__
-
 #define BUILD_OS_ID					2
 
 #ifdef __i386__
-	#define	BUILD_STRING				"linux-x86"
+	#define	BUILD_STRING				"unix-x86"
 	#define CPUSTRING					"x86"
 	#define CPU_EASYARGS				1
 #elif defined(__x86_64__)
-	#define	BUILD_STRING				"linux-x86_64"
+	#define	BUILD_STRING				"unix-x86_64"
 	#define CPUSTRING					"x64"
 	#define CPU_EASYARGS				0
 #elif defined(__ppc__)
-	#define	BUILD_STRING				"linux-ppc"
+	#define	BUILD_STRING				"unix-ppc"
 	#define CPUSTRING					"ppc"
 	#define CPU_EASYARGS				0
 #endif
@@ -177,8 +177,6 @@
 
 #define THREAD_RETURN_TYPE				void *
 
-#endif
-
 #if !defined(ID_LITTLE_ENDIAN) && !defined(ID_BIG_ENDIAN)
 	#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
 		#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
@@ -225,7 +223,7 @@ typedef enum {
 //	CPUID_CMOV							= 0x02000,	// Conditional Move (CMOV) and fast floating point comparison (FCOMI) instructions
 	CPUID_FTZ							= 0x04000,	// Flush-To-Zero mode (denormal results are flushed to zero)
 	CPUID_DAZ							= 0x08000	// Denormals-Are-Zero mode (denormal source operands are set to zero)
-} cpuid_t;
+} id_cpuid_t;
 
 typedef enum {
 	FPU_ROUNDING_TO_NEAREST				= 0,
@@ -316,7 +314,7 @@ double			Sys_ClockTicksPerSecond( void )
 uint64_t Sys_GetTimeMicroseconds( void );
 
 // returns a selection of the CPUID_* flags
-cpuid_t			Sys_GetProcessorId( void );
+id_cpuid_t	Sys_GetProcessorId( void );
 const char *	Sys_GetProcessorString( void );
 
 // sets the FPU precision to double
@@ -570,7 +568,7 @@ public:
 
 	virtual double			GetClockTicks( void ) = 0;
 	virtual double			ClockTicksPerSecond( void ) = 0;
-	virtual cpuid_t			GetProcessorId( void ) = 0;
+	virtual id_cpuid_t		GetProcessorId( void ) = 0;
 	virtual const char *	GetProcessorString( void ) = 0;
 	virtual void			FPU_SetFTZ( bool enable ) = 0;
 	virtual void			FPU_SetDAZ( bool enable ) = 0;
