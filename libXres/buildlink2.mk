# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 04:16:03 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXres.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXRES_BUILDLINK2_MK)
LIBXRES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXres
BUILDLINK_DEPENDS.libXres?=		libXres>=1.0.1
BUILDLINK_PKGSRCDIR.libXres?=		../../wip/libXres

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXres=libXres
BUILDLINK_PREFIX.libXres_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXres+=	include/X11/extensions/XRes.h
BUILDLINK_FILES.libXres+=	lib/libXRes.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/resourceext/buildlink2.mk"

BUILDLINK_TARGETS+=	libXres-buildlink

libXres-buildlink: _BUILDLINK_USE

.endif	# LIBXRES_BUILDLINK2_MK
