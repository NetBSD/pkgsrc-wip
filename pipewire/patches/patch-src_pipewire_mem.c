$NetBSD$

--- src/pipewire/mem.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/pipewire/mem.c
@@ -27,7 +27,7 @@ PW_LOG_TOPIC_EXTERN(log_mem);
 #define PW_LOG_TOPIC_DEFAULT log_mem
 
 #if !defined(__FreeBSD__) && !defined(__MidnightBSD__) && !defined(__GNU__) \
-       && !defined(HAVE_MEMFD_CREATE)
+       && !defined(__NetBSD__) && !defined(HAVE_MEMFD_CREATE)
 /*
  * No glibc wrappers exist for memfd_create(2), so provide our own.
  *
@@ -44,7 +44,7 @@ static inline int memfd_create(const cha
 #define HAVE_MEMFD_CREATE 1
 #endif
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined(__GNU__) || defined(__NetBSD__)
 #define MAP_LOCKED 0
 #endif
 
@@ -567,7 +567,7 @@ struct pw_memblock * pw_mempool_alloc(st
 #else
 	char filename[128];
 	snprintf(filename, sizeof(filename),
-		 "/dev/shm/pipewire-tmpfile:flags=0x%08x,type=%" PRIu32 ",size=%zu:XXXXXX",
+		 "/var/shm/pipewire-tmpfile:flags=0x%08x,type=%" PRIu32 ",size=%zu:XXXXXX",
 		 (unsigned int) flags, type, size);
 
 	b->this.fd = mkostemp(filename, O_CLOEXEC);
