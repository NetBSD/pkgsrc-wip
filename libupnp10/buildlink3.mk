# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/06/22 08:15:35 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libupnp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp

.if !empty(LIBUPNP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libupnp+=		libupnp>=1.0.4
BUILDLINK_PKGSRCDIR.libupnp?=		../../wip/libupnp10
BUILDLINK_FILES.libupnp+=	include/upnp/*.h
BUILDLINK_FILES.libupnp+=	include/upnp/tools/*.h
BUILDLINK_FILES.libupnp+=	include/upnp/upnpdom/*.h
BUILDLINK_FILES.libupnp+=	lib/libupnp.*
.endif	# LIBUPNP_BUILDLINK3_MK

PTHREAD_OPTS+=	require
LDFLAGS+=	${PTHREAD_LDFLAGS}

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
