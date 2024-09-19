# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-network-bytestring

.if !defined(HS_NETWORK_BYTESTRING_BUILDLINK3_MK)
HS_NETWORK_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-bytestring+=	hs-network-bytestring>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-network-bytestring+=	hs-network-bytestring>=0.1.2.1
BUILDLINK_PKGSRCDIR.hs-network-bytestring?=	../../wip/hs-network-bytestring

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_NETWORK_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-bytestring
