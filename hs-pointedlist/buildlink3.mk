# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 07:15:32 phonohawk Exp $

BUILDLINK_TREE+=	hs-pointedlist

.if !defined(HS_POINTEDLIST_BUILDLINK3_MK)
HS_POINTEDLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pointedlist+=	hs-pointedlist>=0.4.0
BUILDLINK_PKGSRCDIR.hs-pointedlist?=	../../wip/hs-pointedlist

.include "../../wip/hs-derive/buildlink3.mk"
.include "../../wip/hs-fclabels/buildlink3.mk"
.endif	# HS_POINTEDLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointedlist
