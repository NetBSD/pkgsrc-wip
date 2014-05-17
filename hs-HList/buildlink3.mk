# $NetBSD: buildlink3.mk,v 1.4 2014/05/17 21:00:05 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HList

.if !defined(HS_HLIST_BUILDLINK3_MK)
HS_HLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HList+=	hs-HList>=0.3.4
BUILDLINK_PKGSRCDIR.hs-HList?=	../../wip/hs-HList

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_HLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HList
