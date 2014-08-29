# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-constraints

.if !defined(HS_CONSTRAINTS_BUILDLINK3_MK)
HS_CONSTRAINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints+=	hs-constraints>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-constraints+=	hs-constraints>=0.3.4.2
BUILDLINK_PKGSRCDIR.hs-constraints?=	../../wip/hs-constraints

.include "../../wip/hs-newtype/buildlink3.mk"
.endif	# HS_CONSTRAINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints
