# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/03/13 12:41:20 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libupnp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp
BUILDLINK_DEPENDS.libupnp?=		libupnp>=1.0.4
BUILDLINK_PKGSRCDIR.libupnp?=		../../wip/libupnp

BUILDLINK_FILES.libupnp+=	include/upnp/*.h
BUILDLINK_FILES.libupnp+=	include/upnp/tools/*.h
BUILDLINK_FILES.libupnp+=	include/upnp/upnpdom/*.h
BUILDLINK_FILES.libupnp+=	lib/libupnp.*

PTHREAD_OPTS+=	require
LDFLAGS+=	${PTHREAD_LDFLAGS}

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
