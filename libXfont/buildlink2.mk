# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 03:33:49 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libXfont.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXFONT_BUILDLINK2_MK)
LIBXFONT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXfont
BUILDLINK_DEPENDS.libXfont?=		libXfont>=1.4.1
BUILDLINK_PKGSRCDIR.libXfont?=		../../wip/libXfont

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXfont=libXfont
BUILDLINK_PREFIX.libXfont_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXfont+=	include/X11/fonts/FS.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/FSproto.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/font.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/fontconf.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/fontenc.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/fontproto.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/fontstruct.h
BUILDLINK_FILES.libXfont+=	include/X11/fonts/fsmasks.h
BUILDLINK_FILES.libXfont+=	lib/libXfont.*

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"

BUILDLINK_TARGETS+=	libXfont-buildlink

libXfont-buildlink: _BUILDLINK_USE

.endif	# LIBXFONT_BUILDLINK2_MK
