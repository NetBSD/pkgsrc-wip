# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/10 18:48:12 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use xlibs
#

.if !defined(XLIBS_BUILDLINK2_MK)
XLIBS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xlibs
BUILDLINK_DEPENDS.xlibs?=		xlibs>=1.0
BUILDLINK_PKGSRCDIR.xlibs?=		../../new/xlibs

EVAL_PREFIX+=	BUILDLINK_PREFIX.xlibs=xlibs
BUILDLINK_PREFIX.xlibs_DEFAULT=	${X11PREFIX}

.include "../../wip/libXmu/buildlink2.mk"
.include "../../wip/libXi/buildlink2.mk"
.include "../../wip/libXv/buildlink2.mk"
.include "../../wip/libXfont/buildlink2.mk"
.include "../../wip/libXres/buildlink2.mk"

BUILDLINK_TARGETS+=	xlibs-buildlink

xlibs-buildlink: _BUILDLINK_USE

.endif	# XLIBS_BUILDLINK2_MK
