# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/27 01:53:46 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libSM.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBSM_BUILDLINK2_MK)
LIBSM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libSM
BUILDLINK_DEPENDS.libSM?=		libSM>=6.0.1
BUILDLINK_PKGSRCDIR.libSM?=		../../wip/libSM

EVAL_PREFIX+=	BUILDLINK_PREFIX.libSM=libSM
BUILDLINK_PREFIX.libSM_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libSM+=	include/X11/SM/SM.h
BUILDLINK_FILES.libSM+=	include/X11/SM/SMlib.h
BUILDLINK_FILES.libSM+=	include/X11/SM/SMproto.h
BUILDLINK_FILES.libSM+=	lib/libSM.*

.include "../../wip/libICE/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"

BUILDLINK_TARGETS+=	libSM-buildlink

libSM-buildlink: _BUILDLINK_USE

.endif	# LIBSM_BUILDLINK2_MK
