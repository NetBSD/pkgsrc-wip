# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/18 03:00:10 bencollver Exp $
#

.if !defined(DUMB_BUILDLINK2_MK)
DUMB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		dumb
BUILDLINK_DEPENDS.dumb?=	dumb>=0.9.2
BUILDLINK_PKGSRCDIR.dumb?=	../../wip/dumb/

EVAL_PREFIX+=	BUILDLINK_PREFIX.dumb=dumb
BUILDLINK_PREFIX.dumb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dumb+=	include/aldumb.h
BUILDLINK_FILES.dumb+=	include/dumb.h
BUILDLINK_FILES.dumb+=	lib/libaldmb.a
BUILDLINK_FILES.dumb+=	lib/libaldmd.a
BUILDLINK_FILES.dumb+=	lib/libdumb.a
BUILDLINK_FILES.dumb+=	lib/libdumbd.a

BUILDLINK_TARGETS+=	dumb-buildlink

dumb-buildlink: _BUILDLINK_USE

.endif	# DUMB_BUILDLINK2_MK
