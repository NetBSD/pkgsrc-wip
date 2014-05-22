# $NetBSD: buildlink3.mk,v 1.4 2014/05/22 21:33:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.4.3
BUILDLINK_PKGSRCDIR.hs-stm?=	../../wip/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
