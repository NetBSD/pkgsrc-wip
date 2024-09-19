# $NetBSD: buildlink3.mk,v 1.14 2011/04/22 13:41:54 obache Exp $

BUILDLINK_TREE+=	compat32_libgpg-error

.if !defined(compat32_LIBGPG_ERROR_BUILDLINK3_MK)
compat32_LIBGPG_ERROR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_libgpg-error+=	compat32_libgpg-error>=0.6
BUILDLINK_ABI_DEPENDS.compat32_libgpg-error+=	compat32_libgpg-error>=1.10nb1
BUILDLINK_PKGSRCDIR.compat32_libgpg-error?=	../../wip/compat32_libgpg-error
BUILDLINK_LIBDIRS.compat32_libgpg-error?=	emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_libgpg-error?=	emul/netbsd32/include

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # COMPAT32_LIBGPG_ERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_libgpg-error
