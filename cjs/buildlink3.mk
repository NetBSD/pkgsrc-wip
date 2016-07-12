# $NetBSD$

BUILDLINK_TREE+=	cjs

.if !defined(CJS_BUILDLINK3_MK)
CJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cjs+=	cjs>=3.0.1
BUILDLINK_PKGSRCDIR.cjs?=	../../wip/cjs

.include "../../wip/spidermonkey24/buildlink3.mk"
.endif	# CJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cjs
