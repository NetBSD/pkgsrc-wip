# $NetBSD: buildlink3.mk,v 1.2 2012/02/01 16:55:58 phonohawk Exp $

BUILDLINK_TREE+=	hs-attempt

.if !defined(HS_ATTEMPT_BUILDLINK3_MK)
HS_ATTEMPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attempt+=	hs-attempt>=0.4.0
BUILDLINK_PKGSRCDIR.hs-attempt?=	../../wip/hs-attempt

.include "../../wip/hs-failure/buildlink3.mk"
.endif	# HS_ATTEMPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attempt
