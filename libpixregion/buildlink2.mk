# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 18:20:11 marc Exp $

.if !defined(LIBPIXREGION_BUILDLINK2_MK)
LIBPIXREGION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libpixregion
BUILDLINK_DEPENDS.libpixregion?=		libpixregion>=0.1.0
BUILDLINK_PKGSRCDIR.libpixregion?=		../../wip/libpixregion

EVAL_PREFIX+=	BUILDLINK_PREFIX.libpixregion=libpixregion
BUILDLINK_PREFIX.libpixregion_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libpixregion+=	include/pixregion.h
BUILDLINK_FILES.libpixregion+=	lib/libpixregion.*

.include "../../wip/slim/buildlink2.mk"

BUILDLINK_TARGETS+=	libpixregion-buildlink

libpixregion-buildlink: _BUILDLINK_USE

.endif	# LIBPIXREGION_BUILDLINK2_MK
