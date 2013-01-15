# $NetBSD: buildlink3.mk,v 1.7 2013/01/15 12:09:44 phonohawk Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.4
BUILDLINK_PKGSRCDIR.hs-network?=	../../wip/hs-network

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
