# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:14 szptvlfn Exp $

BUILDLINK_TREE+=	hs-groupoids

.if !defined(HS_GROUPOIDS_BUILDLINK3_MK)
HS_GROUPOIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-groupoids+=	hs-groupoids>=3.0.1
BUILDLINK_ABI_DEPENDS.hs-groupoids+=	hs-groupoids>=3.0.1.1
BUILDLINK_PKGSRCDIR.hs-groupoids?=	../../wip/hs-groupoids

.endif	# HS_GROUPOIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-groupoids
