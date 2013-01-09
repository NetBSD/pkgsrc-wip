# $NetBSD: buildlink3.mk,v 1.3 2013/01/09 23:22:06 szptvlfn Exp $

BUILDLINK_TREE+=	hs-iconv

.if !defined(HS_ICONV_BUILDLINK3_MK)
HS_ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-iconv+=	hs-iconv>=0.4.0.2
BUILDLINK_PKGSRCDIR.hs-iconv?=	../../wip/hs-iconv

.include "../../converters/libiconv/buildlink3.mk"
.endif # HS_ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-iconv
