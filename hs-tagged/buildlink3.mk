# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/02 16:44:04 phonohawk Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.1.1
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../wip/hs-tagged

.include "../../wip/hs-data-default/buildlink3.mk"
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
