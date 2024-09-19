# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-categories

.if !defined(HS_CATEGORIES_BUILDLINK3_MK)
HS_CATEGORIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-categories+=	hs-categories>=1.0.6
BUILDLINK_ABI_DEPENDS.hs-categories+=	hs-categories>=1.0.6
BUILDLINK_PKGSRCDIR.hs-categories?=	../../wip/hs-categories

.endif	# HS_CATEGORIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-categories
