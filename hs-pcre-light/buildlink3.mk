# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pcre-light

.if !defined(HS_PCRE_LIGHT_BUILDLINK3_MK)
HS_PCRE_LIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pcre-light+=	hs-pcre-light>=0.4
BUILDLINK_ABI_DEPENDS.hs-pcre-light+=	hs-pcre-light>=0.4
BUILDLINK_PKGSRCDIR.hs-pcre-light?=	../../wip/hs-pcre-light

.include "../../devel/pcre/buildlink3.mk"
.endif # HS_PCRE_LIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pcre-light
