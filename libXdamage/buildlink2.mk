# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 03:19:19 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXdamage.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXDAMAGE_BUILDLINK2_MK)
LIBXDAMAGE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXdamage
BUILDLINK_DEPENDS.libXdamage?=		libXdamage>=1.0.0
BUILDLINK_PKGSRCDIR.libXdamage?=		../../wip/libXdamage

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXdamage=libXdamage
BUILDLINK_PREFIX.libXdamage_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXdamage+=	include/X11/extensions/Xdamage.h
BUILDLINK_FILES.libXdamage+=	lib/libXdamage.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXfixes/buildlink2.mk"
.include "../../wip/damageext/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"

BUILDLINK_TARGETS+=	libXdamage-buildlink

libXdamage-buildlink: _BUILDLINK_USE

.endif	# LIBXDAMAGE_BUILDLINK2_MK
