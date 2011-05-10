# $NetBSD: buildlink3.mk,v 1.2 2011/05/10 23:30:31 phonohawk Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.2
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../wip/hs-tagged

.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
