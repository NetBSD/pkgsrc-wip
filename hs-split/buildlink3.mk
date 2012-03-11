# $NetBSD: buildlink3.mk,v 1.2 2012/03/11 07:00:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.1.4
BUILDLINK_PKGSRCDIR.hs-split?=	../../wip/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
