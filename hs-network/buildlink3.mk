# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/12 06:16:58 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_NETWORK_BUILDLINK3_MK:=	${HS_NETWORK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-network
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-network}
BUILDLINK_PACKAGES+=	hs-network
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-network

.if ${HS_NETWORK_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-network?=	build
BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.2.0.1
BUILDLINK_PKGSRCDIR.hs-network?=	../../wip/hs-network
.endif	# HS_NETWORK_BUILDLINK3_MK

.include "../../wip/parsec/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
