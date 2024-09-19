$NetBSD$

uds_beacon.cpp:(.text+0xac9): undefined reference to `CryptoPP::AlignedDeallocate(void*)'

--- externals/cryptopp/cryptopp/config.h.orig	2018-02-22 14:26:16.000000000 +0000
+++ externals/cryptopp/cryptopp/config.h
@@ -688,12 +688,7 @@ NAMESPACE_END
 
 // ***************** Miscellaneous ********************
 
-// Nearly all Intel's and AMD's have SSE. Enable it independent of SSE ASM and intrinscs
-#if (CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32 || CRYPTOPP_BOOL_X64 || CRYPTOPP_BOOL_PPC32 || CRYPTOPP_BOOL_PPC64) && !defined(CRYPTOPP_DISABLE_ASM)
-	#define CRYPTOPP_BOOL_ALIGN16 1
-#else
-	#define CRYPTOPP_BOOL_ALIGN16 0
-#endif
+#define CRYPTOPP_BOOL_ALIGN16 0
 
 // How to allocate 16-byte aligned memory (for SSE2)
 // posix_memalign see https://forum.kde.org/viewtopic.php?p=66274
