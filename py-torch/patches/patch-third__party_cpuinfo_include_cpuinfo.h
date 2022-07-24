$NetBSD$

--- third_party/cpuinfo/include/cpuinfo.h.orig	2022-07-22 04:48:26.695995456 +0000
+++ third_party/cpuinfo/include/cpuinfo.h
@@ -765,7 +765,11 @@ void CPUINFO_ABI cpuinfo_deinitialize(vo
 		bool lwp;
 	};
 
+#ifndef __NetBSD__
 	extern struct cpuinfo_x86_isa cpuinfo_isa;
+#else
+	static struct cpuinfo_x86_isa cpuinfo_isa;
+#endif
 #endif
 
 static inline bool cpuinfo_has_x86_rdtsc(void) {
