# $NetBSD: buildlink3.mk,v 1.4 2014/05/24 22:04:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-temporary

.if !defined(HS_TEMPORARY_BUILDLINK3_MK)
HS_TEMPORARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-temporary+=	hs-temporary>=1.2.0
BUILDLINK_PKGSRCDIR.hs-temporary?=	../../wip/hs-temporary

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_TEMPORARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-temporary
