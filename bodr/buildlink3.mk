# $NetBSD: buildlink3.mk,v 1.1 2011/03/10 12:15:12 ryo-on Exp $

BUILDLINK_TREE+=	bodr

.if !defined(BODR_BUILDLINK3_MK)
BODR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bodr+=	bodr>=8
BUILDLINK_PKGSRCDIR.bodr?=	../../wip/bodr

.endif	# BODR_BUILDLINK3_MK

BUILDLINK_TREE+=	-bodr
