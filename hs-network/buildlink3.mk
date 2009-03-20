# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-network?=	build
BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.2.0.1
BUILDLINK_PKGSRCDIR.hs-network?=	../../wip/hs-network

.include "../../wip/parsec/buildlink3.mk"
.endif # HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
