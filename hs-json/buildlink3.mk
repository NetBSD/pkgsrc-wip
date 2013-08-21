# $NetBSD: buildlink3.mk,v 1.1 2013/08/21 16:45:22 szptvlfn Exp $

BUILDLINK_TREE+=	hs-json

.if !defined(HS_JSON_BUILDLINK3_MK)
HS_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-json+=	hs-json>=0.7
BUILDLINK_PKGSRCDIR.hs-json?=	../../wip/hs-json

.endif	# HS_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-json
