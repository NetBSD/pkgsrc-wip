# $NetBSD: buildlink3.mk,v 1.8 2013/10/26 22:12:42 szptvlfn Exp $

BUILDLINK_TREE+=	hs-uniplate

.if !defined(HS_UNIPLATE_BUILDLINK3_MK)
HS_UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.12
BUILDLINK_PKGSRCDIR.hs-uniplate?=	../../wip/hs-uniplate

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uniplate
