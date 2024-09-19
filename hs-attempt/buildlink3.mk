# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-attempt

.if !defined(HS_ATTEMPT_BUILDLINK3_MK)
HS_ATTEMPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attempt+=	hs-attempt>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-attempt+=	hs-attempt>=0.4.0
BUILDLINK_PKGSRCDIR.hs-attempt?=	../../wip/hs-attempt

.include "../../wip/hs-failure/buildlink3.mk"
.endif	# HS_ATTEMPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attempt
