# $NetBSD: buildlink2.mk,v 1.1 2004/02/10 18:42:28 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXv.
#
# This file was created automatically using createbuildlink-3.1.
#

.if !defined(LIBXV_BUILDLINK2_MK)
LIBXV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXv
BUILDLINK_DEPENDS.libXv?=		libXv>=2.2.1
BUILDLINK_PKGSRCDIR.libXv?=		../../wip/libXv

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXv=libXv
BUILDLINK_PREFIX.libXv_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXv+=	include/X11/extensions/Xvlib.h
BUILDLINK_FILES.libXv+=	lib/libXv.*

.include "../../wip/libX11/buildlink2.mk"

BUILDLINK_TARGETS+=	libXv-buildlink

libXv-buildlink: _BUILDLINK_USE

.endif	# LIBXV_BUILDLINK2_MK
