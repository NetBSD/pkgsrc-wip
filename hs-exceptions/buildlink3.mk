# $NetBSD: buildlink3.mk,v 1.1 2014/01/29 22:25:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-exceptions

.if !defined(HS_EXCEPTIONS_BUILDLINK3_MK)
HS_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-exceptions+=	hs-exceptions>=0.3.3
BUILDLINK_PKGSRCDIR.hs-exceptions?=	../../wip/hs-exceptions

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-exceptions
