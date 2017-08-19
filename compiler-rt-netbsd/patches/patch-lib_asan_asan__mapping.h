$NetBSD$

--- lib/asan/asan_mapping.h.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/asan/asan_mapping.h
@@ -115,6 +115,13 @@
 // || `[0x40000000, 0x47ffffff]` || LowShadow  ||
 // || `[0x00000000, 0x3fffffff]` || LowMem     ||
 //
+// Shadow mapping on NetBSD/x86-64 with SHADOW_OFFSET == 0x400000000000:
+// || `[0x4feffffffe01, 0x7f7ffffff000]` || HighMem    ||
+// || `[0x49fdffffffc0, 0x4feffffffe00]` || HighShadow ||
+// || `[0x480000000000, 0x49fdffffffbf]` || ShadowGap  ||
+// || `[0x400000000000, 0x47ffffffffff]` || LowShadow  ||
+// || `[0x000000000000, 0x3fffffffffff]` || LowMem     ||
+//
 // Default Windows/i386 mapping:
 // (the exact location of HighShadow/HighMem may vary depending
 //  on WoW64, /LARGEADDRESSAWARE, etc).
@@ -140,6 +147,7 @@ static const u64 kPPC64_ShadowOffset64 =
 static const u64 kSystemZ_ShadowOffset64 = 1ULL << 52;
 static const u64 kFreeBSD_ShadowOffset32 = 1ULL << 30;  // 0x40000000
 static const u64 kFreeBSD_ShadowOffset64 = 1ULL << 46;  // 0x400000000000
+static const u64 kNetBSD_ShadowOffset64 = 1ULL << 46;  // 0x400000000000
 static const u64 kWindowsShadowOffset32 = 3ULL << 28;  // 0x30000000
 
 #define SHADOW_SCALE kDefaultShadowScale
@@ -176,8 +184,8 @@ static const u64 kWindowsShadowOffset32 
 #    define SHADOW_OFFSET kPPC64_ShadowOffset64
 #  elif defined(__s390x__)
 #    define SHADOW_OFFSET kSystemZ_ShadowOffset64
-#  elif SANITIZER_FREEBSD
-#    define SHADOW_OFFSET kFreeBSD_ShadowOffset64
+#  elif SANITIZER_NETBSD
+#    define SHADOW_OFFSET kNetBSD_ShadowOffset64
 #  elif SANITIZER_MAC
 #   define SHADOW_OFFSET kDefaultShadowOffset64
 #  elif defined(__mips64)
