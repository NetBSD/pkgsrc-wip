# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-test-framework

.if !defined(HS_TEST_FRAMEWORK_BUILDLINK3_MK)
HS_TEST_FRAMEWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-test-framework+=	hs-test-framework>=0.8
BUILDLINK_ABI_DEPENDS.hs-test-framework+=	hs-test-framework>=0.8
BUILDLINK_PKGSRCDIR.hs-test-framework?=		../../wip/hs-test-framework

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../wip/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-hostname/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.endif	# HS_TEST_FRAMEWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-test-framework
