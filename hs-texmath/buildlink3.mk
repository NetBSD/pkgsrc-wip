# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 22:39:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-texmath

.if !defined(HS_TEXMATH_BUILDLINK3_MK)
HS_TEXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-texmath+=	hs-texmath>=0.6.3
BUILDLINK_PKGSRCDIR.hs-texmath?=	../../wip/hs-texmath

.endif	# HS_TEXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-texmath
