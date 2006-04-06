# $NetBSD: buildlink3.mk,v 1.5 2006/04/06 16:56:37 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libupnp
.endif

.if !empty(LIBUPNP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp
BUILDLINK_API_DEPENDS.libupnp+=		libupnp>=1.2.1
BUILDLINK_PKGSRCDIR.libupnp?=		../../wip/libupnp12
BUILDLINK_FILES.libupnp+=	include/libupnp/*.h
BUILDLINK_FILES.libupnp+=	lib/libupnp.* lib/libthreadutil.* lib/libixml.*
.endif	# LIBUPNP_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
