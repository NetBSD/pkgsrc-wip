# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 09:23:29 phonohawk Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.5
BUILDLINK_PKGSRCDIR.hs-dlist?=	../../wip/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
