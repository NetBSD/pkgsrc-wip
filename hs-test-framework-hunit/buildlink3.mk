# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/12/04 13:33:25 phonohawk Exp $

BUILDLINK_TREE+=	hs-test-framework-hunit

.if !defined(HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework-hunit+=	hs-test-framework-hunit>=0.2.6
BUILDLINK_PKGSRCDIR.hs-test-framework-hunit?=	../../wip/hs-test-framework-hunit

.include "../../wip/hs-HUnit/buildlink3.mk"
.include "../../wip/hs-test-framework/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework-hunit
