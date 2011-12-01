# $NetBSD: buildlink3.mk,v 1.2 2011/12/01 23:03:39 phonohawk Exp $

BUILDLINK_TREE+=	hs-semigroups

.if !defined(HS_SEMIGROUPS_BUILDLINK3_MK)
HS_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroups+=	hs-semigroups>=0.8
BUILDLINK_PKGSRCDIR.hs-semigroups?=	../../wip/hs-semigroups
.endif	# HS_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroups
