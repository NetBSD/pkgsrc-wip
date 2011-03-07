# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/07 12:20:06 jihbed Exp $

BUILDLINK_TREE+=	silo

.if !defined(SILO_BUILDLINK3_MK)
SILO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silo+=	silo>=4.8
BUILDLINK_PKGSRCDIR.silo?=	../../wip/silo

.endif	# SILO_BUILDLINK3_MK

BUILDLINK_TREE+=	-silo
