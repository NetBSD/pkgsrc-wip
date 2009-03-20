# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $
#

BUILDLINK_TREE+=	hs-pcre-light

.if !defined(HS_PCRE_LIGHT_BUILDLINK3_MK)
HS_PCRE_LIGHT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-pcre-light?=	build
BUILDLINK_API_DEPENDS.hs-pcre-light+=	hs-pcre-light>=0.3.1
BUILDLINK_PKGSRCDIR.hs-pcre-light?=	../../wip/hs-pcre-light

.include "../../devel/pcre/buildlink3.mk"
.endif # HS_PCRE_LIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pcre-light
