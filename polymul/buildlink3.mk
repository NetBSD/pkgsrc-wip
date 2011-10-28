# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/28 20:22:15 jihbed Exp $

BUILDLINK_TREE+=	polymul

.if !defined(POLYMUL_BUILDLINK3_MK)
POLYMUL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polymul+=	polymul>=1.01
BUILDLINK_PKGSRCDIR.polymul?=	../../wip/polymul
.endif	# POLYMUL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polymul
