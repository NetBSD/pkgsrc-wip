# $NetBSD: buildlink3.mk,v 1.4 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-json

.if !defined(HS_JSON_BUILDLINK3_MK)
HS_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-json+=	hs-json>=0.7
BUILDLINK_PKGSRCDIR.hs-json?=	../../wip/hs-json

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-json
