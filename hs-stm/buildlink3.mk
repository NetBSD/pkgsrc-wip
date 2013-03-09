# $NetBSD: buildlink3.mk,v 1.3 2013/03/09 22:32:47 szptvlfn Exp $

BUILDLINK_TREE+=	hs-stm

.if !defined(HS_STM_BUILDLINK3_MK)
HS_STM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm+=	hs-stm>=2.4.2
BUILDLINK_PKGSRCDIR.hs-stm?=	../../wip/hs-stm
.endif	# HS_STM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm
