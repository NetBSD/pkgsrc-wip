# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 04:05:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXrandr.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXRANDR_BUILDLINK2_MK)
LIBXRANDR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXrandr
BUILDLINK_DEPENDS.libXrandr?=		libXrandr>=1.0.1
BUILDLINK_PKGSRCDIR.libXrandr?=		../../wip/libXrandr

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXrandr=libXrandr
BUILDLINK_PREFIX.libXrandr_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXrandr+=	include/X11/extensions/Xrandr.h
BUILDLINK_FILES.libXrandr+=	lib/libXrandr.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/randrext/buildlink2.mk"

BUILDLINK_TARGETS+=	libXrandr-buildlink

libXrandr-buildlink: _BUILDLINK_USE

.endif	# LIBXRANDR_BUILDLINK2_MK
