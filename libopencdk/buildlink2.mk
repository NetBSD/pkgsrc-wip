# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/13 02:29:36 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libopencdk.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(LIBOPENCDK_BUILDLINK2_MK)
LIBOPENCDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libopencdk
BUILDLINK_DEPENDS.libopencdk?=		libopencdk>=0.4.1
BUILDLINK_PKGSRCDIR.libopencdk?=		../../devel/libopencdk

EVAL_PREFIX+=	BUILDLINK_PREFIX.libopencdk=libopencdk
BUILDLINK_PREFIX.libopencdk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libopencdk+=	include/opencdk.h
BUILDLINK_FILES.libopencdk+=	lib/libopencdk.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"

BUILDLINK_TARGETS+=	libopencdk-buildlink

libopencdk-buildlink: _BUILDLINK_USE

.endif	# LIBOPENCDK_BUILDLINK2_MK
