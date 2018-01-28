# $NetBSD: hacks.mk,v 1.1.1.1 2008/07/12 01:35:10 bsadewitz Exp $
#
.if !defined(RATPROXY_HACKS_MK)
RATPROXY_HACKS_MK=	# defined
#
.include "../../mk/bsd.fast.prefs.mk"
#
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wno-pointer-sign
.endif
.endif
