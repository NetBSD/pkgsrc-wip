# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-text-icu

.if !defined(HS_TEXT_ICU_BUILDLINK3_MK)
HS_TEXT_ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-icu+=	hs-text-icu>=0.6.3
BUILDLINK_ABI_DEPENDS.hs-text-icu+=	hs-text-icu>=0.6.3.4
BUILDLINK_PKGSRCDIR.hs-text-icu?=	../../wip/hs-text-icu

.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_TEXT_ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-icu
