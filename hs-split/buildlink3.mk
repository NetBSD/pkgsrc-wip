# $NetBSD: buildlink3.mk,v 1.3 2013/08/17 20:02:54 szptvlfn Exp $

BUILDLINK_TREE+=	hs-split

.if !defined(HS_SPLIT_BUILDLINK3_MK)
HS_SPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-split+=	hs-split>=0.2.2
BUILDLINK_PKGSRCDIR.hs-split?=	../../wip/hs-split
.endif	# HS_SPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-split
