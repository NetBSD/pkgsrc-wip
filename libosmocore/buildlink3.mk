# $NetBSD: buildlink3.mk,v 1.1 2011/08/02 22:19:13 khorben Exp $

BUILDLINK_TREE+=	libosmocore

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosmocore+=	libosmocore>=0.1.30
BUILDLINK_PKGSRCDIR.libosmocore?=	../../wip/libosmocore

.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosmocore
