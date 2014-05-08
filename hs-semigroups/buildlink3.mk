# $NetBSD: buildlink3.mk,v 1.9 2014/05/08 00:35:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroups

.if !defined(HS_SEMIGROUPS_BUILDLINK3_MK)
HS_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroups+=	hs-semigroups>=0.13.0
BUILDLINK_PKGSRCDIR.hs-semigroups?=	../../wip/hs-semigroups

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-nats/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroups
