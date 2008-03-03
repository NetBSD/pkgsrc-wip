# $NetBSD: hacks.mk,v 1.4 2008/03/03 05:55:02 bsadewitz Exp $

.if !defined(MESALIBS_HACKS_MK)
MESALIBS_HACKS_MK=	# defined

### [Fri Dec 30 21:00:59 CET 2005 : schwarz]
### make sys/types.h not conflict with inttypes.h
### (issue is specific to IRIX 5.3)
###
.if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
post-wrapper:
		${MKDIR} ${BUILDLINK_DIR}/include/sys && ${GREP} -v '^typedef.*[^u_]int[12368]*_t;' /usr/include/sys/types.h > ${BUILDLINK_DIR}/include/sys/types.h
# should match int8_t, int16_t, and int32_t (only)
.endif

.include "../../mk/compiler.mk"
###
### Ordinarily, this is defined by the build.  However, in pkgsrc,
### policy dictates that we do it here.  Let's trust a semi-modern
### gcc with -ffast-math for now.
###
.if !empty(CC_VERSION:Mgcc-[34]*)
PKG_HACKS+= 	 	no-strict-aliasing
CFLAGS+= 	 	-fno-strict-aliasing
PKG_HACKS+=		gcc-fast-math
CFLAGS+= 	 	-ffast-math
.endif

.if !empty(PKG_OPTIONS:Mdri) && !empty(CC_VERSION:Mgcc-[4-9]*)
PKG_HACKS+= 	 	gcc-hidden-visibility
CFLAGS+=	 	-fvisibility=hidden
.endif

.endif
