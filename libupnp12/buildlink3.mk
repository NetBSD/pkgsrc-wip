# $NetBSD: buildlink3.mk,v 1.3 2006/02/18 11:41:34 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libupnp
.endif

.if !empty(LIBUPNP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp
BUILDLINK_DEPENDS.libupnp+=		libupnp>=1.2.1
BUILDLINK_RECOMMENDED.libupnp?=		libupnp>=1.2.1
BUILDLINK_PKGSRCDIR.libupnp?=		../../wip/libupnp12
BUILDLINK_FILES.libupnp+=	include/libupnp/*.h
BUILDLINK_FILES.libupnp+=	lib/libupnp.* lib/libthreadutil.* lib/libixml.*
.endif	# LIBUPNP_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
