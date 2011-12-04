# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/12/04 13:40:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-test-framework-quickcheck2

.if !defined(HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework-quickcheck2+=	hs-test-framework-quickcheck2>=0.2.10
BUILDLINK_PKGSRCDIR.hs-test-framework-quickcheck2?=	../../wip/hs-test-framework-quickcheck2

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../wip/hs-test-framework/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework-quickcheck2
