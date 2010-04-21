# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/21 03:29:41 phonohawk Exp $

BUILDLINK_TREE+=	hs-HList

.if !defined(HS_HLIST_BUILDLINK3_MK)
HS_HLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HList+=	hs-HList>=0.2
BUILDLINK_PKGSRCDIR.hs-HList?=	../../wip/hs-HList
.endif	# HS_HLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HList
