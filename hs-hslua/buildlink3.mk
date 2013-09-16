# $NetBSD: buildlink3.mk,v 1.1 2013/09/16 21:06:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=0.3.6
BUILDLINK_PKGSRCDIR.hs-hslua?=	../../wip/hs-hslua

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
