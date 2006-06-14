# $NetBSD: buildlink3.mk,v 1.2 2006/06/14 16:28:21 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libupnp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp

.if ${LIBUPNP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libupnp+=	libupnp>=1.4.0
BUILDLINK_PKGSRCDIR.libupnp?=	../../wip/libupnp14
.endif	# LIBUPNP_BUILDLINK3_MK

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin" || ${OPSYS} == "BSDOS"
BUILDLINK_LIBS.libupnp+=	-lcompat     # XXX need this for ftime(3)
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
