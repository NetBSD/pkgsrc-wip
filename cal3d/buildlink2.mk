# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/05 03:48:09 mpasternak Exp $

.if !defined(CAL3D_BUILDLINK2_MK)
CAL3D_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		cal3d
BUILDLINK_DEPENDS.cal3d?=	cal3d>=0.9
BUILDLINK_PKGSRCDIR.cal3d?=	../../wip/cal3d

EVAL_PREFIX+=			BUILDLINK_PREFIX.cal3d=cal3d
BUILDLINK_PREFIX.cal3d_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cal3d=	include/cal3d/*
BUILDLINK_FILES.cal3d+=	lib/libcal3d.*

BUILDLINK_TARGETS+=	cal3d-buildlink

cal3d-buildlink: _BUILDLINK_USE

.endif	# CAL3D_BUILDLINK2_MK
