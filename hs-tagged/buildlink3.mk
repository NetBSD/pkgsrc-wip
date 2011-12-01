# $NetBSD: buildlink3.mk,v 1.3 2011/12/01 23:05:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.2.3
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../wip/hs-tagged

.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
