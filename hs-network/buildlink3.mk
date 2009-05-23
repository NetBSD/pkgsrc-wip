# $NetBSD: buildlink3.mk,v 1.3 2009/05/23 07:31:23 phonohawk Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.2.1.2
BUILDLINK_PKGSRCDIR.hs-network?=	../../wip/hs-network

.include "../../wip/parsec/buildlink3.mk"
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
