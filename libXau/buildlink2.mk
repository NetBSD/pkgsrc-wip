# $NetBSD: buildlink2.mk,v 1.2 2003/11/28 04:54:33 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libXau.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXAU_BUILDLINK2_MK)
LIBXAU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libXau
BUILDLINK_DEPENDS.libXau?=		libXau>=0.1
BUILDLINK_PKGSRCDIR.libXau?=		../../wip/libXau

EVAL_PREFIX+=	BUILDLINK_PREFIX.libXau=libXau
BUILDLINK_PREFIX.libXau_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libXau+=	include/X11/Xauth.h
BUILDLINK_FILES.libXau+=	lib/libXau.*

BUILDLINK_TARGETS+=	libXau-buildlink

libXau-buildlink: _BUILDLINK_USE

.endif	# LIBXAU_BUILDLINK2_MK
