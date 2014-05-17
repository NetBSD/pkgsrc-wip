# $NetBSD: buildlink3.mk,v 1.3 2014/05/17 20:28:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.7.0
BUILDLINK_PKGSRCDIR.hs-dlist?=	../../wip/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
