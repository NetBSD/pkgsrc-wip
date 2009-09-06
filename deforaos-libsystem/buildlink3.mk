# $NetBSD: buildlink3.mk,v 1.1 2009/09/06 21:54:31 khorben Exp $

BUILDLINK_TREE+=	deforaos-libsystem

.if !defined(DEFORAOS_LIBSYSTEM_BUILDLINK3_MK)
DEFORAOS_LIBSYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libsystem+=	deforaos-libsystem>=0.1.2
BUILDLINK_PKGSRCDIR.deforaos-libsystem?=	../../wip/deforaos-libsystem

#.include "../../security/openssl/buildlink3.mk"
.endif	# DEFORAOS_LIBSYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libsystem
