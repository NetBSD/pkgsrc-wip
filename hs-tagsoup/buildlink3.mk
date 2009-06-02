# $NetBSD: buildlink3.mk,v 1.2 2009/06/02 06:56:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-tagsoup

.if !defined(HS_TAGSOUP_BUILDLINK3_MK)
HS_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.6
BUILDLINK_PKGSRCDIR.hs-tagsoup?=	../../wip/tagsoup

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.endif	# HS_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagsoup
