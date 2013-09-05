# $NetBSD: buildlink3.mk,v 1.1 2013/09/05 20:46:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-categories

.if !defined(HS_CATEGORIES_BUILDLINK3_MK)
HS_CATEGORIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-categories+=	hs-categories>=1.0.6
BUILDLINK_PKGSRCDIR.hs-categories?=	../../wip/hs-categories

.endif	# HS_CATEGORIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-categories
