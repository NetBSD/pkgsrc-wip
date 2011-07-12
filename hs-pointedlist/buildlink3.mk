# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 05:23:23 phonohawk Exp $

BUILDLINK_TREE+=	hs-pointedlist

.if !defined(HS_POINTEDLIST_BUILDLINK3_MK)
HS_POINTEDLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pointedlist+=	hs-pointedlist>=0.4
BUILDLINK_PKGSRCDIR.hs-pointedlist?=	../../wip/hs-pointedlist

.include "../../wip/hs-binary/buildlink3.mk"
.include "../../wip/hs-derive/buildlink3.mk"
.include "../../wip/hs-fclabels/buildlink3.mk"
.endif	# HS_POINTEDLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointedlist
