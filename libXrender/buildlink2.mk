# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 02:57:45 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXrender.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXRENDER_BUILDLINK2_MK)
LIBXRENDER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXrender
BUILDLINK_DEPENDS.libXrender?=		libXrender>=0.8.3
BUILDLINK_PKGSRCDIR.libXrender?=		../../wip/libXrender

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXrender=libXrender
BUILDLINK_PREFIX.libXrender_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXrender+=	include/X11/extensions/Xrender.h
BUILDLINK_FILES.libXrender+=	lib/libXrender.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../x11/render/buildlink2.mk"

BUILDLINK_TARGETS+=	libXrender-buildlink

libXrender-buildlink: _BUILDLINK_USE

.endif	# LIBXRENDER_BUILDLINK2_MK
