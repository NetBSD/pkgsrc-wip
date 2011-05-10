# $NetBSD: buildlink3.mk,v 1.2 2011/05/10 12:36:51 phonohawk Exp $

BUILDLINK_TREE+=	hs-utility-ht

.if !defined(HS_UTILITY_HT_BUILDLINK3_MK)
HS_UTILITY_HT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0
BUILDLINK_PKGSRCDIR.hs-utility-ht?=	../../wip/hs-utility-ht
.endif	# HS_UTILITY_HT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utility-ht
