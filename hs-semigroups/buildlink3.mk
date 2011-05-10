# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/10 23:24:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-semigroups

.if !defined(HS_SEMIGROUPS_BUILDLINK3_MK)
HS_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroups+=	hs-semigroups>=0.5
BUILDLINK_PKGSRCDIR.hs-semigroups?=	../../wip/hs-semigroups
.endif	# HS_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroups
