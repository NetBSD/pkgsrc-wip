# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 08:15:51 phonohawk Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.1
BUILDLINK_PKGSRCDIR.hs-split?=	../../wip/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
