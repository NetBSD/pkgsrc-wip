# $NetBSD: buildlink2.mk,v 1.1 2003/11/27 02:42:06 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXfixes.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXFIXES_BUILDLINK2_MK)
LIBXFIXES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXfixes
BUILDLINK_DEPENDS.libXfixes?=		libXfixes>=2.0.0
BUILDLINK_PKGSRCDIR.libXfixes?=		../../wip/libXfixes

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXfixes=libXfixes
BUILDLINK_PREFIX.libXfixes_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXfixes+=	include/X11/extensions/Xfixes.h
BUILDLINK_FILES.libXfixes+=	lib/libXfixes.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/fixesext/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"

BUILDLINK_TARGETS+=	libXfixes-buildlink

libXfixes-buildlink: _BUILDLINK_USE

.endif	# LIBXFIXES_BUILDLINK2_MK
