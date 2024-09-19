# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-test-framework-quickcheck2

.if !defined(HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework-quickcheck2+=	hs-test-framework-quickcheck2>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-test-framework-quickcheck2+=	hs-test-framework-quickcheck2>=0.3.0.1
BUILDLINK_PKGSRCDIR.hs-test-framework-quickcheck2?=	../../wip/hs-test-framework-quickcheck2

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-test-framework/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_QUICKCHECK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework-quickcheck2
