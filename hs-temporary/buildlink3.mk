# $NetBSD: buildlink3.mk,v 1.2 2014/03/07 12:40:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-temporary

.if !defined(HS_TEMPORARY_BUILDLINK3_MK)
HS_TEMPORARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-temporary+=	hs-temporary>=1.2.0
BUILDLINK_PKGSRCDIR.hs-temporary?=	../../wip/hs-temporary

.include "../../wip/hs-exceptions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_TEMPORARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-temporary
