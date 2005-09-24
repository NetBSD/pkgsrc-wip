# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/09/24 14:46:01 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libupnp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp
BUILDLINK_DEPENDS.libupnp?=		libupnp>=1.2.1
BUILDLINK_RECOMMENDED.libupnp?=		libupnp>=1.2.1
BUILDLINK_PKGSRCDIR.libupnp?=		../../wip/libupnp12

BUILDLINK_FILES.libupnp+=	include/libupnp/*.h
BUILDLINK_FILES.libupnp+=	lib/libupnp.* lib/libthreadutil.* lib/libixml.*

.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
