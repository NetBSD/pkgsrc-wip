# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-test-framework-hunit

.if !defined(HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework-hunit+=	hs-test-framework-hunit>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-test-framework-hunit+=	hs-test-framework-hunit>=0.3.0
BUILDLINK_PKGSRCDIR.hs-test-framework-hunit?=	../../wip/hs-test-framework-hunit

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-HUnit/buildlink3.mk"
.include "../../wip/hs-test-framework/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework-hunit
