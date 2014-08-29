# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-utility-ht

.if !defined(HS_UTILITY_HT_BUILDLINK3_MK)
HS_UTILITY_HT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.8
BUILDLINK_ABI_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.8
BUILDLINK_PKGSRCDIR.hs-utility-ht?=	../../wip/hs-utility-ht
.endif	# HS_UTILITY_HT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utility-ht
