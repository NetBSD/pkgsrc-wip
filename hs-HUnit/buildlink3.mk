# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/02 06:57:32 phonohawk Exp $

BUILDLINK_TREE+=	hs-HUnit

.if !defined(HS_HUNIT_BUILDLINK3_MK)
HS_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HUnit+=	hs-HUnit>=1.2.0.3
BUILDLINK_PKGSRCDIR.hs-HUnit?=	../../wip/hs-HUnit
.endif	# HS_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HUnit
