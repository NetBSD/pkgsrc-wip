# $NetBSD: buildlink2.mk,v 1.2 2004/02/10 18:29:05 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXi.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXI_BUILDLINK2_MK)
LIBXI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXi
BUILDLINK_DEPENDS.libXi?=		libXi>=6.0.1
BUILDLINK_PKGSRCDIR.libXi?=		../../wip/libXi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXi=libXi
BUILDLINK_PREFIX.libXi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXi+=	lib/libXi.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/libXext/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"

BUILDLINK_TARGETS+=	libXi-buildlink

libXi-buildlink: _BUILDLINK_USE

.endif	# LIBXI_BUILDLINK2_MK
