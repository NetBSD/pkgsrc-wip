# $NetBSD$

BUILDLINK_TREE+=	spidermonkey31

.if !defined(SPIDERMONKEY31_BUILDLINK3_MK)
SPIDERMONKEY31_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey31+=	spidermonkey31>=31.2.0.rc0
BUILDLINK_PKGSRCDIR.spidermonkey31?=	../../wip/spidermonkey31

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# SPIDERMONKEY31_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey31
