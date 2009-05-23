# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/23 07:36:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-network-bytestring

.if !defined(HS_NETWORK_BYTESTRING_BUILDLINK3_MK)
HS_NETWORK_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-bytestring+=	hs-network-bytestring>=0.1.2.1
BUILDLINK_PKGSRCDIR.hs-network-bytestring?=	../../wip/hs-network-bytestring

.include "../../wip/hs-network/buildlink3.mk"
.endif	# HS_NETWORK_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-bytestring
