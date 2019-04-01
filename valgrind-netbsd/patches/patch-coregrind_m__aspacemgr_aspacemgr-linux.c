$NetBSD$

--- coregrind/m_aspacemgr/aspacemgr-linux.c.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/m_aspacemgr/aspacemgr-linux.c
@@ -32,7 +32,7 @@
    The GNU General Public License is contained in the file COPYING.
 */
 
-#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /* *************************************************************
    DO NOT INCLUDE ANY OTHER FILES HERE.
@@ -306,7 +306,7 @@ static Int      nsegments_used = 0;
 
 
 Addr VG_(clo_aspacem_minAddr)
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
    = (Addr) 0x04000000; // 64M
 #elif defined(VGO_darwin)
 # if VG_WORDSIZE == 4
@@ -872,7 +872,7 @@ static void sync_check_mapping_callback 
          cmp_devino = False;
 #endif
 
-#if defined(VGO_darwin)
+#if defined(VGO_darwin) || defined(VGO_netbsd)
       // GrP fixme kernel info doesn't have dev/inode
       cmp_devino = False;
       
@@ -1638,6 +1638,32 @@ Addr VG_(am_startup) ( Addr sp_at_startu
 
    suggested_clstack_end = -1; // ignored; Mach-O specifies its stack
 
+   // --- Freebsd ------------------------------------------
+
+#elif defined(VGO_netbsd)
+
+# if VG_WORDSIZE == 4
+   aspacem_maxAddr = VG_PGROUNDDN( sp_at_startup ) - 1;
+# else
+   aspacem_maxAddr = (Addr) (Addr)0x800000000 - 1; // 32G
+#  ifdef ENABLE_INNER
+   { Addr cse = VG_PGROUNDDN( sp_at_startup ) - 1;
+     if (aspacem_maxAddr > cse)
+        aspacem_maxAddr = cse;
+   }
+#    endif
+# endif
+
+   aspacem_cStart = aspacem_minAddr;
+   aspacem_vStart = VG_PGROUNDUP((aspacem_minAddr + aspacem_maxAddr + 1) / 2);
+
+#  ifdef ENABLE_INNER
+   aspacem_vStart -= 0x10000000; // 256M
+#  endif
+    
+   suggested_clstack_end = aspacem_maxAddr - 16*1024*1024ULL
+                                           + VKI_PAGE_SIZE;
+
    // --- Solaris ------------------------------------------
 #elif defined(VGO_solaris)
 #  if VG_WORDSIZE == 4
@@ -3797,13 +3823,93 @@ Bool VG_(get_changed_segments)(
    return !css_overflowed;
 }
 
-#endif // defined(VGO_darwin)
-
 /*------END-procmaps-parser-for-Darwin---------------------------*/
 
+/*------BEGIN-procmaps-parser-for-NetBSD------------------------*/
+
+#elif defined(VGO_netbsd)
+    
+ /* Size of a smallish table used to read /proc/self/map entries. */
+ #define M_PROCMAP_BUF 10485760 /* 10M */
+ 
+ /* static ... to keep it out of the stack frame. */
+ static char procmap_buf[M_PROCMAP_BUF];
+static void parse_procselfmaps (
+      void (*record_mapping)( Addr addr, SizeT len, UInt prot,
+                              ULong dev, ULong ino, Off64T offset,
+                              const HChar* filename ),
+      void (*record_gap)( Addr addr, SizeT len )
+   )
+{       
+    Int    i;
+    Addr   start, endPlusOne, gapStart; 
+    char* filename;
+    char   *p;
+    UInt          prot;
+    ULong  foffset, dev, ino;
+    struct vki_kinfo_vmentry *kve;
+    vki_size_t len;
+    Int    oid[5];
+    SysRes sres;
+
+    foffset = ino = 0; /* keep gcc-4.1.0 happy */
+
+    oid[0] = VKI_CTL_VM;
+    oid[1] = VKI_VM_PROC;
+    oid[2] = VKI_VM_PROC_MAP;
+    oid[3] = sr_Res(VG_(do_syscall0)(__NR_getpid));
+    oid[4] = sizeof(struct vki_kinfo_vmentry);
+
+    len = sizeof(procmap_buf);
+
+    sres = VG_(do_syscall6)(__NR___sysctl, (UWord)oid, 5, (UWord)procmap_buf,
+       (UWord)&len, 0, 0);
+    if (sr_isError(sres)) {
+       VG_(debugLog)(0, "procselfmaps", "sysctll %ld\n", sr_Err(sres));
+       ML_(am_exit)(1);
+    }
+
+    gapStart = Addr_MIN;
+    i = 0;
+    p = procmap_buf;
+    while (p < (char *)procmap_buf + len) {
+       kve = (struct vki_kinfo_vmentry *)p;
+       start      = (UWord)kve->kve_start;
+       endPlusOne = (UWord)kve->kve_end;
+       foffset    = kve->kve_offset;
+       filename   = kve->kve_path;
+       dev        = kve->kve_vn_fsid;
+       ino        = kve->kve_vn_fileid;
+       if (filename[0] != '/') {
+         filename = NULL;
+         foffset = 0;
+       }
+
+       prot = 0;
+       if (kve->kve_protection & VKI_KVME_PROT_READ)  prot |= VKI_PROT_READ;
+       if (kve->kve_protection & VKI_KVME_PROT_WRITE) prot |= VKI_PROT_WRITE;
+       if (kve->kve_protection & VKI_KVME_PROT_EXEC)  prot |= VKI_PROT_EXEC;
+       
+       if (record_gap && gapStart < start)
+          (*record_gap) ( gapStart, start-gapStart );
+         
+       if (record_mapping && start < endPlusOne)
+          (*record_mapping) ( start, endPlusOne-start,
+                              prot, dev, ino,
+                              foffset, filename );                                                                                                           
+       gapStart = endPlusOne;
+       p += sizeof(struct vki_kinfo_vmentry);
+    }
+
+    if (record_gap && gapStart < Addr_MAX)
+       (*record_gap) ( gapStart, Addr_MAX - gapStart + 1 );
+}
+
+/*------END-procmaps-parser-for-Netbsd--------------------------*/
+
 /*------BEGIN-procmaps-parser-for-Solaris------------------------*/
 
-#if defined(VGO_solaris)
+#elif defined(VGO_solaris)
 
 /* Note: /proc/self/xmap contains extended information about already
    materialized mappings whereas /proc/self/rmap contains information about
@@ -4113,7 +4219,7 @@ Bool VG_(am_search_for_new_segment)(Addr
 
 /*------END-procmaps-parser-for-Solaris--------------------------*/
 
-#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris)
+#endif // defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 
 /*--------------------------------------------------------------------*/
 /*--- end                                                          ---*/
