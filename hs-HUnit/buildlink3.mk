# $NetBSD: buildlink3.mk,v 1.4 2013/03/02 11:18:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-HUnit

.if !defined(HS_HUNIT_BUILDLINK3_MK)
HS_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HUnit+=	hs-HUnit>=1.2.5
BUILDLINK_PKGSRCDIR.hs-HUnit?=	../../wip/hs-HUnit
.endif	# HS_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HUnit
