# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HUnit

.if !defined(HS_HUNIT_BUILDLINK3_MK)
HS_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HUnit+=	hs-HUnit>=1.2.5
BUILDLINK_ABI_DEPENDS.hs-HUnit+=	hs-HUnit>=1.2.5.2
BUILDLINK_PKGSRCDIR.hs-HUnit?=		../../wip/hs-HUnit
.endif	# HS_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HUnit
