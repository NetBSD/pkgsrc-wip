# $NetBSD: buildlink3.mk,v 1.2 2014/05/21 21:04:44 szptvlfn Exp $

BUILDLINK_TREE+=	hs-network-bytestring

.if !defined(HS_NETWORK_BYTESTRING_BUILDLINK3_MK)
HS_NETWORK_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-bytestring+=	hs-network-bytestring>=0.1.2.1
BUILDLINK_PKGSRCDIR.hs-network-bytestring?=	../../wip/hs-network-bytestring

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_NETWORK_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-bytestring
