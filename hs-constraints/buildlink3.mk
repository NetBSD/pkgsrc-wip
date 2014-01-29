# $NetBSD: buildlink3.mk,v 1.1 2014/01/29 22:21:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-constraints

.if !defined(HS_CONSTRAINTS_BUILDLINK3_MK)
HS_CONSTRAINTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-constraints+=	hs-constraints>=0.3.4
BUILDLINK_PKGSRCDIR.hs-constraints?=	../../wip/hs-constraints

.include "../../wip/hs-newtype/buildlink3.mk"
.endif	# HS_CONSTRAINTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-constraints
