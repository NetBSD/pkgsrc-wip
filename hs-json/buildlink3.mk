# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-json

.if !defined(HS_JSON_BUILDLINK3_MK)
HS_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-json+=	hs-json>=0.7
BUILDLINK_ABI_DEPENDS.hs-json+=	hs-json>=0.7
BUILDLINK_PKGSRCDIR.hs-json?=	../../wip/hs-json

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-json
