$NetBSD$

--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2018-12-18 12:55:50.000000000 +0000
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp
@@ -21,6 +21,9 @@
 #include <sys/mman.h>
 #include <sys/soundcard.h>
 #include <unistd.h>
+#if defined(RT_OS_NETBSD)
+#include <strings.h>
+#endif
 
 #include <iprt/alloc.h>
 #include <iprt/uuid.h> /* For PDMIBASE_2_PDMDRV. */
@@ -132,6 +135,7 @@ static OSSAUDIOCFG s_OSSConf =
 };
 
 
+#if !defined(RT_OS_NETBSD)
 /* http://www.df.lth.se/~john_e/gems/gem002d.html */
 static uint32_t popcount(uint32_t u)
 {
@@ -142,6 +146,7 @@ static uint32_t popcount(uint32_t u)
     u = ( u&0x0000ffff) + (u>>16);
     return u;
 }
+#endif
 
 
 static uint32_t lsbindex(uint32_t u)
