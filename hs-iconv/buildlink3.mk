# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-iconv

.if !defined(HS_ICONV_BUILDLINK3_MK)
HS_ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-iconv+=	hs-iconv>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-iconv+=	hs-iconv>=0.4.0.2nb1
BUILDLINK_PKGSRCDIR.hs-iconv?=		../../wip/hs-iconv

.include "../../converters/libiconv/buildlink3.mk"
.endif # HS_ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-iconv
