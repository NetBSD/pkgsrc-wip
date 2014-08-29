# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pointedlist

.if !defined(HS_POINTEDLIST_BUILDLINK3_MK)
HS_POINTEDLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pointedlist+=	hs-pointedlist>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-pointedlist+=	hs-pointedlist>=0.4.0.3
BUILDLINK_PKGSRCDIR.hs-pointedlist?=	../../wip/hs-pointedlist

.include "../../wip/hs-derive/buildlink3.mk"
.include "../../wip/hs-fclabels/buildlink3.mk"
.endif	# HS_POINTEDLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointedlist
