$NetBSD$

--- VTK/ThirdParty/netcdf/vtknetcdf/libsrc/mmapio.c.orig	2026-03-31 10:30:33.000000000 +0000
+++ VTK/ThirdParty/netcdf/vtknetcdf/libsrc/mmapio.c
@@ -42,7 +42,7 @@
 #error mmap not fully implemented: missing MAP_ANONYMOUS
 #endif
 
-#ifdef HAVE_MREMAP
+#if defined(HAVE_MREMAP) && defined(__linux__)
   /* This is conditionalized by __USE_GNU ; why? */
   extern void *mremap(void*,size_t,size_t,int);
 # ifndef MREMAP_MAYMOVE
@@ -441,9 +441,14 @@ mmapio_pad_length(ncio* nciop, off_t len
 	}
 
 #ifdef HAVE_MREMAP
+#if defined(__linux__)
 	newmem = (char*)mremap(mmapio->memory,mmapio->alloc,newsize,MREMAP_MAYMOVE);
 	if(newmem == NULL) return NC_ENOMEM;
 #else
+	newmem = (char*)mremap(mmapio->memory,mmapio->alloc,NULL,newsize,0);
+	if(newmem == MAP_FAILED) return NC_ENOMEM;
+#endif
+#else
         /* note: mmapio->mapfd >= 0 => persist */
         newmem = (char*)mmap(NULL,newsize,
                                     mmapio->mapfd >= 0?(PROT_READ|PROT_WRITE):(PROT_READ),
