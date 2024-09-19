$NetBSD$

--- sys/sys_local.h.orig	2019-02-02 17:51:38.000000000 +0000
+++ sys/sys_local.h
@@ -31,7 +31,7 @@ public:
 
 	virtual double			GetClockTicks( void );
 	virtual double			ClockTicksPerSecond( void );
-	virtual cpuid_t			GetProcessorId( void );
+	virtual id_cpuid_t		GetProcessorId( void );
 	virtual const char *	GetProcessorString( void );
 	virtual void			FPU_SetFTZ( bool enable );
 	virtual void			FPU_SetDAZ( bool enable );
