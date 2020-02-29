# $NetBSD: buildlink3.mk,v 1.18 2016/08/17 23:13:11 maya Exp $

BUILDLINK_TREE+=	compat32_libgcrypt

.if !defined(COMPAT32_LIBGCRYPT_BUILDLINK3_MK)
COMPAT32_LIBGCRYPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_libgcrypt+=	compat32_libgcrypt>=1.2.0
BUILDLINK_ABI_DEPENDS.compat32_libgcrypt+=	compat32_libgcrypt>=1.6.0
BUILDLINK_PKGSRCDIR.compat32_libgcrypt?=	../../wip/compat32_libgcrypt
BUILDLINK_LIBDIRS.compat32_libgcrypt?=		emul/netbsd32/lib

.include "../../wip/compat32_libgpg-error/buildlink3.mk"
.endif # COMPAT32_LIBGCRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_libgcrypt
