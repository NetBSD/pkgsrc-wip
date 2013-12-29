# $NetBSD: buildlink3.mk,v 1.3 2013/12/29 16:17:59 khorben Exp $

BUILDLINK_TREE+=	deforaos-libsystem

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.1.2
BUILDLINK_PKGSRCDIR.deforaos-libsystem?=	../../wip/deforaos-libsystem

.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libsystem
