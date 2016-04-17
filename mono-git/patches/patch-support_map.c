$NetBSD$

--- support/map.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ support/map.c
@@ -3922,12 +3922,17 @@ int Mono_Posix_ToMountFlags (guint64 x, 
 int Mono_Posix_FromMremapFlags (guint64 x, guint64 *r)
 {
 	*r = 0;
+#ifndef __NetBSD__
 	if ((x & Mono_Posix_MremapFlags_MREMAP_MAYMOVE) == Mono_Posix_MremapFlags_MREMAP_MAYMOVE)
 #ifdef MREMAP_MAYMOVE
 		*r |= MREMAP_MAYMOVE;
 #else /* def MREMAP_MAYMOVE */
 		{errno = EINVAL; return -1;}
 #endif /* ndef MREMAP_MAYMOVE */
+#else /* def __NetBSD__ */
+	if ((x & Mono_Posix_MremapFlags_MREMAP_MAYMOVE) != Mono_Posix_MremapFlags_MREMAP_MAYMOVE)
+		*r = MAP_FIXED;
+#endif /* def __NetBSD__ */
 	if (x == 0)
 		return 0;
 	return 0;
@@ -3936,12 +3941,17 @@ int Mono_Posix_FromMremapFlags (guint64 
 int Mono_Posix_ToMremapFlags (guint64 x, guint64 *r)
 {
 	*r = 0;
+#ifndef __NetBSD__
 	if (x == 0)
 		return 0;
 #ifdef MREMAP_MAYMOVE
 	if ((x & MREMAP_MAYMOVE) == MREMAP_MAYMOVE)
 		*r |= Mono_Posix_MremapFlags_MREMAP_MAYMOVE;
 #endif /* ndef MREMAP_MAYMOVE */
+#else /* def __NetBSD__ */
+	if ((x & MAP_FIXED) != MAP_FIXED)
+		*r |= Mono_Posix_MremapFlags_MREMAP_MAYMOVE;
+#endif
 	return 0;
 }
 
@@ -9314,4 +9324,3 @@ int Mono_Posix_ToXattrFlags (int x, int 
 #endif /* ndef XATTR_REPLACE */
 	return 0;
 }
-
