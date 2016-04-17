$NetBSD$

--- support/sys-mman.c.orig	2016-04-16 14:26:45.000000000 +0000
+++ support/sys-mman.c
@@ -109,8 +109,15 @@ Mono_Posix_Syscall_mremap (void *old_add
 	if (Mono_Posix_FromMremapFlags (flags, &_flags) == -1)
 		return MAP_FAILED;
 
+#if defined(linux)
 	return mremap (old_address, (size_t) old_size, (size_t) new_size,
 			(unsigned long) _flags);
+#elif defined(__NetBSD__)
+	return mremap (old_address, (size_t) old_size, old_address,
+			(size_t) new_size, (unsigned long) _flags);
+#else
+#error Port me
+#endif
 }
 #endif /* def HAVE_MREMAP */
 
