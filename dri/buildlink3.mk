# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/03 14:43:27 pallegra Exp $

BUILDLINK_TREE+=	dri

.if !defined(DRI_BUILDLINK3_MK)
DRI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dri+=	dri>=7.7
BUILDLINK_PKGSRCDIR.dri?=	../../wip/dri

.endif	# DRI_BUILDLINK3_MK

BUILDLINK_TREE+=	-dri
