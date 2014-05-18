# $NetBSD: buildlink3.mk,v 1.10 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroups

.if !defined(HS_SEMIGROUPS_BUILDLINK3_MK)
HS_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroups+=	hs-semigroups>=0.13.0
BUILDLINK_PKGSRCDIR.hs-semigroups?=	../../wip/hs-semigroups

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-nats/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroups
