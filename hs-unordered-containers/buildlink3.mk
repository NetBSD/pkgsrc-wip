# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/04 06:45:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.1.4
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../wip/hs-unordered-containers

.include "../../wip/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
