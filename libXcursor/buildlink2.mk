# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 03:07:10 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXcursor.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXCURSOR_BUILDLINK2_MK)
LIBXCURSOR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXcursor
BUILDLINK_DEPENDS.libXcursor?=		libXcursor>=1.1.1
BUILDLINK_PKGSRCDIR.libXcursor?=		../../wip/libXcursor

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXcursor=libXcursor
BUILDLINK_PREFIX.libXcursor_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXcursor+=	include/X11/Xcursor/Xcursor.h
BUILDLINK_FILES.libXcursor+=	lib/libXcursor.*

.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXrender/buildlink2.mk"
.include "../../wip/libXfixes/buildlink2.mk"

BUILDLINK_TARGETS+=	libXcursor-buildlink

libXcursor-buildlink: _BUILDLINK_USE

.endif	# LIBXCURSOR_BUILDLINK2_MK
