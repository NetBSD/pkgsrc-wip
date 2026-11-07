$NetBSD$

NetBSD/aarch64 (AAPCS64) defines __ALIGNBYTES as sizeof(__int128_t) - 1
(sys/arch/arm/include/cdefs.h).  With 3, CMSG_NXTHDR() lands in padding,
reads cmsg_len 0 and noq-udp spins forever on the first received datagram.

--- ../vendor/libc-0.2.190/src/unix/bsd/netbsdlike/netbsd/aarch64.rs.orig	2026-11-07 10:22:50.257978696 +0000
+++ ../vendor/libc-0.2.190/src/unix/bsd/netbsdlike/netbsd/aarch64.rs	2026-11-07 10:22:50.260188475 +0000
@@ -65,7 +65,7 @@
     }
 }
 
-pub(crate) const _ALIGNBYTES: usize = size_of::<c_int>() - 1;
+pub(crate) const _ALIGNBYTES: usize = size_of::<u128>() - 1;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
 pub const PT_SETREGS: c_int = PT_FIRSTMACH + 1;
