# $NetBSD: buildlink3.mk,v 1.2 2011/07/27 06:25:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.2
BUILDLINK_PKGSRCDIR.hs-stm?=	../../wip/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
