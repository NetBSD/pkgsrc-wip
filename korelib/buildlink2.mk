# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/04 00:09:35 jeremy-c-reed Exp $

.if !defined(KORELIB_BUILDLINK2_MK)
KORELIB_BUILDLINK2_MK=    # defined

BUILDLINK_PACKAGES+=		korelib
BUILDLINK_DEPENDS.korelib?=	korelib>=1.0
BUILDLINK_PKGSRCDIR.korelib?=	../../devel/korelib

EVAL_PREFIX+=	BUILDLINK_PREFIX.korelib=korelib
BUILDLINK_PREFIX.korelib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.korelib=		include/kore/*.h
BUILDLINK_FILES.korelib+=		lib/libkore.*

BUILDLINK_TARGETS+=	korelib-buildlink

korelib-buildlink:	_BUILDLINK_USE

.endif  # KORELIB_BUILDLINK2_MK
