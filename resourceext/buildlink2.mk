# $NetBSD: buildlink2.mk,v 1.2 2003/12/30 22:59:11 cjep Exp $
#
# This Makefile fragment is included by packages that use resourceext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(RESOURCEEXT_BUILDLINK2_MK)
RESOURCEEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			resourceext
BUILDLINK_DEPENDS.resourceext?=		resourceext>=1.0
BUILDLINK_PKGSRCDIR.resourceext?=		../../wip/resourceext

EVAL_PREFIX+=	BUILDLINK_PREFIX.resourceext=resourceext
BUILDLINK_PREFIX.resourceext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.resourceext+=	include/X11/extensions/XResproto.h

BUILDLINK_TARGETS+=	resourceext-buildlink

resourceext-buildlink: _BUILDLINK_USE

.endif	# RESOURCEEXT_BUILDLINK2_MK
