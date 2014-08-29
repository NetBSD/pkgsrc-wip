# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-texmath

.if !defined(HS_TEXMATH_BUILDLINK3_MK)
HS_TEXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-texmath+=	hs-texmath>=0.6.6
BUILDLINK_ABI_DEPENDS.hs-texmath+=	hs-texmath>=0.6.6
BUILDLINK_PKGSRCDIR.hs-texmath?=	../../wip/hs-texmath

.include "../../wip/hs-pandoc-types/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.endif	# HS_TEXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-texmath
