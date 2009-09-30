# $NetBSD: buildlink3.mk,v 1.1 2009/09/30 08:15:35 thomasklausner Exp $

BUILDLINK_TREE+=	openjdk

.if !defined(OPENJDK_BUILDLINK3_MK)
OPENJDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openjdk+=	openjdk>=1.7.0.72.20090924
BUILDLINK_PKGSRCDIR.openjdk?=	../../wip/openjdk

.endif	# OPENJDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk
