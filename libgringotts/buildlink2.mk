# $NetBSD: buildlink2.mk,v 1.3 2004/04/15 00:49:39 thomasklausner Exp $
#
# This Makefile fragment is included by packages that use libgringotts.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBGRINGOTTS_BUILDLINK2_MK)
LIBGRINGOTTS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgringotts
BUILDLINK_DEPENDS.libgringotts?=		libgringotts>=1.2.1
BUILDLINK_PKGSRCDIR.libgringotts?=		../../wip/libgringotts

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgringotts=libgringotts
BUILDLINK_PREFIX.libgringotts_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgringotts+=	include/libgringotts.h
BUILDLINK_FILES.libgringotts+=	lib/libgringotts.*

.include "../../security/libmcrypt/buildlink2.mk"
.include "../../security/mhash/buildlink2.mk"

BUILDLINK_TARGETS+=	libgringotts-buildlink

libgringotts-buildlink: _BUILDLINK_USE

.endif	# LIBGRINGOTTS_BUILDLINK2_MK
