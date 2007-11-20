# $NetBSD: hacks.mk,v 1.1 2007/11/20 05:56:10 bsadewitz Exp $

.if !defined(GRUB2_HACKS_MK)
GRUB2_HACKS_MK=	# defined
.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[34]*)
CFLAGS+=	-fno-strict-aliasing
PKG_HACKS+=	no-strict-aliasing
.endif

.include "../../mk/bsd.fast.prefs.mk"
PKG_HACKS+=	x86-gcc-sanity
##
## Remove problematic CPUFLAGS/COPTS/CFLAGS
##
BUILDLINK_TRANSFORM+=	rm-optarg:-msse rm-optarg:-msse2 rm-optarg:-m3dnow
BUILDLINK_TRANSFORM+=	rm-optarg:-mcpu
##
## Make sure that this compiles stricly as i386 code.
##
GRUB_MACHINE_ARCH=	${"${MACHINE_ARCH}" == "x86_64":?i386:${MACHINE_ARCH}}

.if ${MACHINE_ARCH} == "i386"
BUILDLINK_TRANSFORM+=	opt:-march:-march=i386
.else
BUILDLINK_TRANSFORM+=	rm:-march
.endif

.endif 			# GRUB2_HACKS_MK
