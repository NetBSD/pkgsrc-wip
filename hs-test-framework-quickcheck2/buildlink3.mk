# $NetBSD: buildlink3.mk,v 1.3 2014/05/20 21:23:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-test-framework-quickcheck2

.if !defined(HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework-quickcheck2+=	hs-test-framework-quickcheck2>=0.3.0
BUILDLINK_PKGSRCDIR.hs-test-framework-quickcheck2?=	../../wip/hs-test-framework-quickcheck2

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-test-framework/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework-quickcheck2
