# $NetBSD: buildlink2.mk,v 1.3 2004/02/01 18:55:48 minskim Exp $
#
# This Makefile fragment is included by packages that use libX11.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(LIBX11_BUILDLINK2_MK)
LIBX11_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libX11
BUILDLINK_DEPENDS.libX11?=		libX11>=6.2.1
BUILDLINK_PKGSRCDIR.libX11?=		../../wip/libX11

EVAL_PREFIX+=	BUILDLINK_PREFIX.libX11=libX11
BUILDLINK_PREFIX.libX11_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libX11+=	include/X11/ImUtil.h
BUILDLINK_FILES.libX11+=	include/X11/XKBlib.h
BUILDLINK_FILES.libX11+=	include/X11/Xcms.h
BUILDLINK_FILES.libX11+=	include/X11/Xlib.h
BUILDLINK_FILES.libX11+=	include/X11/Xlibint.h
BUILDLINK_FILES.libX11+=	include/X11/Xlocale.h
BUILDLINK_FILES.libX11+=	include/X11/Xresource.h
BUILDLINK_FILES.libX11+=	include/X11/Xutil.h
BUILDLINK_FILES.libX11+=	include/X11/cursorfont.h
BUILDLINK_FILES.libX11+=	include/X11/region.h
BUILDLINK_FILES.libX11+=	lib/libX11.*

.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xtrans/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"

BUILDLINK_TARGETS+=	libX11-buildlink

libX11-buildlink: _BUILDLINK_USE

.endif	# LIBX11_BUILDLINK2_MK
