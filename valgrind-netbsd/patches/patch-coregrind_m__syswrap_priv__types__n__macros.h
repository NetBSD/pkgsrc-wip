$NetBSD$

--- coregrind/m_syswrap/priv_types_n_macros.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_syswrap/priv_types_n_macros.h
@@ -52,6 +52,9 @@
 /* Arguments for a syscall. */
 typedef
    struct SyscallArgs {
+#if defined(VGO_netbsd)
+      Word klass;
+#endif
       Word sysno;
       RegWord arg1;
       RegWord arg2;
@@ -102,6 +105,15 @@ typedef
       Int o_arg6;
       Int uu_arg7;
       Int uu_arg8;
+#     elif defined(VGP_amd64_netbsd)
+      Int o_arg1;
+      Int o_arg2;
+      Int o_arg3;
+      Int o_arg4;
+      Int o_arg5;
+      Int o_arg6;
+      Int s_arg7; 
+      Int s_arg8; 
 #     elif defined(VGP_mips32_linux)
       Int o_arg1;
       Int o_arg2;
@@ -185,7 +197,7 @@ typedef
 extern
 SyscallTableEntry* ML_(get_linux_syscall_entry)( UInt sysno );
 
-#elif defined(VGO_darwin)
+#elif defined(VGO_darwin) || defined(VGO_netbsd)
 /* XXX: Darwin still uses the old scheme of exposing the table
    array(s) and size(s) directly to syswrap-main.c.  This should be
    fixed. */
@@ -275,7 +287,7 @@ SyscallTableEntry* ML_(get_solaris_sysca
     vgSysWrap_##auxstr##_##name##_after
 
 /* Add a generic wrapper to a syscall table. */
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 #  define GENX_(sysno, name)  WRAPPER_ENTRY_X_(generic, sysno, name)
 #  define GENXY(sysno, name)  WRAPPER_ENTRY_XY(generic, sysno, name)
 #elif defined(VGO_darwin)
@@ -290,6 +302,10 @@ SyscallTableEntry* ML_(get_solaris_sysca
 #define LINX_(sysno, name)    WRAPPER_ENTRY_X_(linux, sysno, name) 
 #define LINXY(sysno, name)    WRAPPER_ENTRY_XY(linux, sysno, name)
 
+/* Add a NetBSD-specific, arch-independent wrapper to a syscall
+   table. */
+#define BSDX_(sysno, name)    WRAPPER_ENTRY_X_(netbsd, sysno, name)
+#define BSDXY(sysno, name)    WRAPPER_ENTRY_XY(netbsd, sysno, name)
 
 /* ---------------------------------------------------------------------
    Macros useful for writing wrappers concisely.  These refer to the
@@ -335,7 +351,7 @@ static inline UWord getRES ( SyscallStat
    return sr_Res(st->sres);
 }
 
-#if defined(VGO_darwin) || defined(VGO_solaris)
+#if defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 static inline UWord getRESHI ( SyscallStatus* st ) {
    vg_assert(st->what == SsComplete);
    vg_assert(!sr_isError(st->sres));
@@ -356,6 +372,13 @@ static inline UWord getERR ( SyscallStat
         status->sres = VG_(mk_SysRes_Success)(zzz);  \
    } while (0)
 
+#ifdef VGO_netbsd
+#define SET_STATUS_Success2(zzz, zzz2)               \
+   do { status->what = SsComplete;                   \
+        status->sres = VG_(mk_SysRes_amd64_netbsd)(zzz, zzz2, False);  \
+   } while (0)
+#endif
+
 #define SET_STATUS_Failure(zzz)                      \
    do { Word wzz = (Word)(zzz);                      \
         /* Catch out wildly bogus error values. */   \
@@ -419,7 +442,7 @@ static inline UWord getERR ( SyscallStat
 #  define PRA7(s,t,a) PSRAn(7,s,t,a)
 #  define PRA8(s,t,a) PSRAn(8,s,t,a)
 
-#elif defined(VGP_amd64_darwin) || defined(VGP_amd64_solaris)
+#elif defined(VGP_amd64_darwin) || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
    /* Up to 8 parameters, 6 in registers, 2 on the stack. */
 #  define PRA1(s,t,a) PRRAn(1,s,t,a)
 #  define PRA2(s,t,a) PRRAn(2,s,t,a)
