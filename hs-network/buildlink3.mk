# $NetBSD: buildlink3.mk,v 1.8 2013/02/23 13:27:10 phonohawk Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.4.1
BUILDLINK_PKGSRCDIR.hs-network?=	../../wip/hs-network

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
