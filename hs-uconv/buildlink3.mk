# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	hs-uconv

.if !defined(HS_UCONV_BUILDLINK3_MK)
HS_UCONV_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-uconv?=	build
BUILDLINK_API_DEPENDS.hs-uconv+=	hs-uconv>=0.0.3
BUILDLINK_PKGSRCDIR.hs-uconv?=	../../wip/hs-uconv

.include "../../textproc/icu/buildlink3.mk"
.endif # HS_UCONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uconv
