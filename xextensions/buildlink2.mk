# $NetBSD: buildlink2.mk,v 1.1 2003/11/27 00:02:27 xtraeme Exp $
#
# This Makefile fragment is included by packages that use xextensions.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XEXTENSIONS_BUILDLINK2_MK)
XEXTENSIONS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xextensions
BUILDLINK_DEPENDS.xextensions?=		xextensions>=1.0
BUILDLINK_PKGSRCDIR.xextensions?=		../../wip/xextensions

EVAL_PREFIX+=	BUILDLINK_PREFIX.xextensions=xextensions
BUILDLINK_PREFIX.xextensions_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xextensions+=	include/X11/extensions/*.h

BUILDLINK_TARGETS+=	xextensions-buildlink

xextensions-buildlink: _BUILDLINK_USE

.endif	# XEXTENSIONS_BUILDLINK2_MK
