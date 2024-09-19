$NetBSD$

--- coregrind/m_aspacemgr/aspacemgr-common.c.orig	2018-08-06 07:22:24.000000000 +0000
+++ coregrind/m_aspacemgr/aspacemgr-common.c
@@ -146,6 +146,9 @@ SysRes VG_(am_do_mmap_NO_NOTIFY)( Addr s
    SysRes res;
    aspacem_assert(VG_IS_PAGE_ALIGNED(offset));
 
+   if (start == 0 && flags & VKI_MAP_FIXED)
+      __builtin_trap();
+
 #  if defined(VGP_arm64_linux)
    res = VG_(do_syscall6)(__NR3264_mmap, (UWord)start, length, 
                          prot, flags, fd, offset);
@@ -161,6 +164,11 @@ SysRes VG_(am_do_mmap_NO_NOTIFY)( Addr s
         || defined(VGP_mips64_linux) || defined(VGP_arm64_linux)
    res = VG_(do_syscall6)(__NR_mmap, (UWord)start, length, 
                          prot, flags, fd, offset);
+#  elif defined(VGP_amd64_netbsd)
+   if (flags & VKI_MAP_ANONYMOUS && fd == 0)
+      fd = -1;
+   res = VG_(do_syscall7)(__NR_mmap, (UWord)start, length,
+                          prot, flags, fd, 0, offset);
 #  elif defined(VGP_x86_darwin)
    if (fd == 0  &&  (flags & VKI_MAP_ANONYMOUS)) {
        fd = -1;  // MAP_ANON with fd==0 is EINVAL
@@ -221,6 +229,12 @@ SysRes ML_(am_do_extend_mapping_NO_NOTIF
              0/*flags, meaning: must be at old_addr, else FAIL */,
              0/*new_addr, is ignored*/
           );
+#  elif defined(VGO_netbsd)
+   return VG_(do_syscall5)(
+             __NR_mremap, 
+             old_addr, old_len, 0/*newp*/, new_len, 
+             VKI_MAP_FIXED/*flags, meaning: must be at old_addr, else FAIL */
+          );
 #  else
 #    error Unknown OS
 #  endif
@@ -242,6 +256,12 @@ SysRes ML_(am_do_relocate_nooverlap_mapp
              VKI_MREMAP_MAYMOVE|VKI_MREMAP_FIXED/*move-or-fail*/,
              new_addr
           );
+#  elif defined(VGO_netbsd)
+   return VG_(do_syscall5)(
+             __NR_mremap, 
+             old_addr, old_len, new_addr, new_len, 
+             VKI_MAP_FIXED/*move-or-fail*/
+          );
 #  else
 #    error Unknown OS
 #  endif
@@ -257,7 +277,7 @@ SysRes ML_(am_open) ( const HChar* pathn
    /* ARM64 wants to use __NR_openat rather than __NR_open. */
    SysRes res = VG_(do_syscall4)(__NR_openat,
                                  VKI_AT_FDCWD, (UWord)pathname, flags, mode);
-#  elif defined(VGO_linux) || defined(VGO_darwin)
+#  elif defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    SysRes res = VG_(do_syscall3)(__NR_open, (UWord)pathname, flags, mode);
 #  elif defined(VGO_solaris)
    SysRes res = VG_(do_syscall4)(__NR_openat, VKI_AT_FDCWD, (UWord)pathname,
@@ -285,7 +305,7 @@ Int ML_(am_readlink)(const HChar* path, 
 #  if defined(VGP_arm64_linux)
    res = VG_(do_syscall4)(__NR_readlinkat, VKI_AT_FDCWD,
                                            (UWord)path, (UWord)buf, bufsiz);
-#  elif defined(VGO_linux) || defined(VGO_darwin)
+#  elif defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    res = VG_(do_syscall3)(__NR_readlink, (UWord)path, (UWord)buf, bufsiz);
 #  elif defined(VGO_solaris)
    res = VG_(do_syscall4)(__NR_readlinkat, VKI_AT_FDCWD, (UWord)path,
@@ -298,7 +318,7 @@ Int ML_(am_readlink)(const HChar* path, 
 
 Int ML_(am_fcntl) ( Int fd, Int cmd, Addr arg )
 {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    SysRes res = VG_(do_syscall3)(__NR_fcntl, fd, cmd, arg);
 #  elif defined(VGO_darwin)
    SysRes res = VG_(do_syscall3)(__NR_fcntl_nocancel, fd, cmd, arg);
@@ -314,7 +334,7 @@ Bool ML_(am_get_fd_d_i_m)( Int fd, 
                            /*OUT*/ULong* dev, 
                            /*OUT*/ULong* ino, /*OUT*/UInt* mode )
 {
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    SysRes          res;
    struct vki_stat buf;
 #  if defined(VGO_linux) && defined(__NR_fstat64)
@@ -330,7 +350,11 @@ Bool ML_(am_get_fd_d_i_m)( Int fd, 
       return True;
    }
 #  endif
+#  if defined(VGO_netbsd)
+   res = VG_(do_syscall2)(__NR___fstat50, fd, (UWord)&buf);
+#else
    res = VG_(do_syscall2)(__NR_fstat, fd, (UWord)&buf);
+#endif
    if (!sr_isError(res)) {
       *dev  = (ULong)buf.st_dev;
       *ino  = (ULong)buf.st_ino;
@@ -393,6 +417,9 @@ Bool ML_(am_resolve_filename) ( Int fd, 
    else
       return False;
 
+#elif defined(VGO_netbsd)
+   return False;
+
 #  else
 #     error Unknown OS
 #  endif
