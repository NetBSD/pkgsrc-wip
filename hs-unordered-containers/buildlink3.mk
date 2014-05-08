# $NetBSD: buildlink3.mk,v 1.4 2014/05/08 00:36:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-unordered-containers

.if !defined(HS_UNORDERED_CONTAINERS_BUILDLINK3_MK)
HS_UNORDERED_CONTAINERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unordered-containers+=	hs-unordered-containers>=0.2.4
BUILDLINK_PKGSRCDIR.hs-unordered-containers?=	../../wip/hs-unordered-containers

.include "../../wip/hs-hashable/buildlink3.mk"
.endif	# HS_UNORDERED_CONTAINERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unordered-containers
