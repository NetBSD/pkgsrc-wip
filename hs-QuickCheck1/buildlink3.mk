# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-QuichCheck1

.if !defined(HS_QUICHCHECK1_BUILDLINK3_MK)
HS_QUICHCHECK1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuichCheck1+=	hs-QuichCheck1>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-QuichCheck1+=	hs-QuichCheck1>=1.2.0.0
BUILDLINK_PKGSRCDIR.hs-QuichCheck1?=	../../wip/hs-QuickCheck1
.endif	# HS_QUICHCHECK1_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuichCheck1
