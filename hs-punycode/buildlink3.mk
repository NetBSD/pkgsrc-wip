# $NetBSD: buildlink3.mk,v 1.3 2014/05/19 21:28:50 szptvlfn Exp $

BUILDLINK_TREE+=	hs-punycode

.if !defined(HS_PUNYCODE_BUILDLINK3_MK)
HS_PUNYCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-punycode+=	hs-punycode>=0.0
BUILDLINK_PKGSRCDIR.hs-punycode?=	../../wip/hs-punycode

.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../wip/hs-text-icu/buildlink3.mk"
.endif	# HS_PUNYCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-punycode
