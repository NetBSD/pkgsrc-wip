# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/11/19 21:50:59 daprice Exp $
#
# This Makefile fragment is included by packages that use libgrass5.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBGRASS5_BUILDLINK2_MK)
LIBGRASS5_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgrass5
BUILDLINK_DEPENDS.libgrass5?=		libgrass5>=1.0.0
BUILDLINK_PKGSRCDIR.libgrass5?=		../../wip/libgrass5

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgrass5=libgrass5
BUILDLINK_PREFIX.libgrass5_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgrass5+=	include/P_datetime.h
BUILDLINK_FILES.libgrass5+=	include/P_site.h
BUILDLINK_FILES.libgrass5+=	include/datetime.h
BUILDLINK_FILES.libgrass5+=	include/gis.h
BUILDLINK_FILES.libgrass5+=	include/gisdefs.h
BUILDLINK_FILES.libgrass5+=	include/imagedefs.h
BUILDLINK_FILES.libgrass5+=	include/imagery.h
BUILDLINK_FILES.libgrass5+=	include/libgrass.h
BUILDLINK_FILES.libgrass5+=	include/site.h
BUILDLINK_FILES.libgrass5+=	lib/libgrass5.*

BUILDLINK_TARGETS+=	libgrass5-buildlink

libgrass5-buildlink: _BUILDLINK_USE

.endif	# LIBGRASS5_BUILDLINK2_MK
