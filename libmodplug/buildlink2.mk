# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/21 21:01:13 bencollver Exp $

.if !defined(LIBMODPLUG_BUILDLINK2_MK)
LIBMODPLUG_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			libmodplug
BUILDLINK_DEPENDS.libmodplug?=		libmodplug>=0.7
BUILDLINK_PKGSRCDIR.libmodplug?=	../../audio/libmodplug

EVAL_PREFIX+=				BUILDLINK_PREFIX.libmodplug=libmodplug
BUILDLINK_PREFIX.libmodplug_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmodplug=	include/libmodplug/*
BUILDLINK_FILES.libmodplug+=	lib/libmodplug.*

BUILDLINK_TARGETS+=	libmodplug-buildlink

libmodplug-buildlink: _BUILDLINK_USE

.endif	# LIBMODPLUG_BUILDLINK2_MK
