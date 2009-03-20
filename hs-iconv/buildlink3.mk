# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-iconv

.if !defined(HS_ICONV_BUILDLINK3_MK)
HS_ICONV_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-iconv?=	build
BUILDLINK_API_DEPENDS.hs-iconv+=	hs-iconv>=0.4.0.2
BUILDLINK_PKGSRCDIR.hs-iconv?=	../../wip/hs-iconv

.include "../../converters/libiconv/buildlink3.mk"
.endif # HS_ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-iconv
