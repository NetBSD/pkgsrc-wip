# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 03:27:08 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXext.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXEXT_BUILDLINK2_MK)
LIBXEXT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXext
BUILDLINK_DEPENDS.libXext?=		libXext>=6.4.1
BUILDLINK_PKGSRCDIR.libXext?=		../../wip/libXext

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXext=libXext
BUILDLINK_PREFIX.libXext_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXext+=	lib/libXext.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"

BUILDLINK_TARGETS+=	libXext-buildlink

libXext-buildlink: _BUILDLINK_USE

.endif	# LIBXEXT_BUILDLINK2_MK
