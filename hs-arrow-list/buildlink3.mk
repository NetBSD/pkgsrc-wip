# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/01/05 14:03:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-arrow-list

.if !defined(HS_ARROW_LIST_BUILDLINK3_MK)
HS_ARROW_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-arrow-list+=	hs-arrow-list>=0.2.0
BUILDLINK_PKGSRCDIR.hs-arrow-list?=	../../wip/hs-arrow-list

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_ARROW_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-arrow-list
