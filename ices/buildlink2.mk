# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/29 00:53:47 icmp Exp $

.if !defined(LIBSHOUT_BUILDLINK2_MK)
LIBSHOUT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libshout
BUILDLINK_DEPENDS.libshout?=	libshout>=1.0.9
BUILDLINK_PKGSRCDIR.libshout?=	../../wip/libshout

EVAL_PREFIX+=	BUILDLINK_PREFIX.libshout=libshout
BUILDLINK_PREFIX.libshout_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libshout+=	include/shout/shout.h
BUILDLINK_FILES.libshout+=	lib/libshout.so

BUILDLINK_TARGETS+=	libshout-buildlink

libshout-buildlink: _BUILDLINK_USE

.endif # LIBSHOUT_BUILDLINK2_MK
