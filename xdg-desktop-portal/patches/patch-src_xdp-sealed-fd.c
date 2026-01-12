$NetBSD$

* memfd_create and seals available on NetBSD>=11

--- src/xdp-sealed-fd.c.orig	2026-01-12 13:31:04.004734564 +0000
+++ src/xdp-sealed-fd.c
@@ -80,6 +80,7 @@ xdp_sealed_fd_new_take_memfd (int      m
 
   g_return_val_if_fail (fd != -1, NULL);
 
+#if !defined(__NetBSD__) || __NetBSD_Version__ >= 1100000000
   seals = fcntl (fd, F_GET_SEALS);
   if (seals == -1)
    {
@@ -106,6 +107,7 @@ xdp_sealed_fd_new_take_memfd (int      m
                    "fcntl F_ADD_SEALS: %s", g_strerror (saved_errno));
       return NULL;
     }
+#endif
 
   sealed_fd = g_object_new (XDP_TYPE_SEALED_FD, NULL);
   sealed_fd->fd = g_steal_fd (&fd);
@@ -127,7 +129,11 @@ xdp_sealed_fd_new_from_bytes (GBytes  *b
 
   g_return_val_if_fail (bytes != NULL, NULL);
 
+#if !defined(__NetBSD__) || __NetBSD_Version__ >= 1100000000
   fd = memfd_create ("xdp-sealed-fd", MFD_ALLOW_SEALING);
+#else
+  fd = shm_open ("xdp-sealed-fd", O_RDWR, 0600);
+#endif
   if (fd == -1)
     {
       int saved_errno;
@@ -181,6 +187,7 @@ xdp_sealed_fd_new_from_bytes (GBytes  *b
       return NULL;
     }
 
+#if !defined(__NetBSD__) || __NetBSD_Version__ >= 1100000000
   if (fcntl (fd, F_ADD_SEALS, REQUIRED_SEALS) == -1)
     {
       saved_errno = errno;
@@ -190,6 +197,7 @@ xdp_sealed_fd_new_from_bytes (GBytes  *b
                    "fcntl F_ADD_SEALS: %s", g_strerror (saved_errno));
       return NULL;
     }
+#endif
 
   sealed_fd = g_object_new (XDP_TYPE_SEALED_FD, NULL);
   sealed_fd->fd = g_steal_fd (&fd);
