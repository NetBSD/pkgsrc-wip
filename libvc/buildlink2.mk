# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/08 10:37:08 bjan2 Exp $

.if !defined(LIBVC_BUILDLINK_MK)
LIBVC_BUILDLINK2_MK=   # defined

BUILDLINK_PACKAGES+=		libvc
BUILDLINK_DEPENDS.libvc?=	libvc>=003
BUILDLINK_PKGSRCDIR.libvc?=	../../wip/libvc

EVAL_PREFIX+=				BUILDLINK_PREFIX.libvc=libvc
BUILDLINK_PREFIX.libvc_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libvc=	include/vc.h
BUILDLINK_FILES.libvc+=	lib/libvc.*

BUILDLINK_TARGETS+=             libvc-buildlink

libvc-buildlink: _BUILDLINK_USE

.endif
