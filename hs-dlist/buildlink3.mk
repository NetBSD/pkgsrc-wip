# $NetBSD: buildlink3.mk,v 1.2 2013/11/29 14:05:15 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.6
BUILDLINK_PKGSRCDIR.hs-dlist?=	../../wip/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
