# $NetBSD$

.if !defined(XOREOS_HACKS_MK)
XOREOS_HACKS_MK=	defined

# [Tue Dec 15 15:49:14 SAST 2020 : yhardy]
# On i386 archs src/common/uuid.cpp fails to compile because 64-bit
# atomic operations are needed. Forcing -march=i586 (or better) avoids
# that (i[56]86 provide required).
.if ${MACHINE_ARCH} == "i386"
PKG_HACKS+=	i386-atomicops
CXXFLAGS+=	-march=i586
.endif

# [Tue Dec 15 15:49:14 SAST 2020 : yhardy]
# On NetBSD/powerpc, we don't have native 8-byte atomics, but xoreos
# needs it for a global uint64_t  UID, so here we need libatomic.
.if ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=     powerpc-libatomic
.include "../../devel/libatomic/buildlink3.mk"
.endif

.endif	# XOREOS_HACKS_MK
