# $NetBSD$

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=3.9.0nb20151127
BUILDLINK_PKGSRCDIR.libunwind?=		../../wip/libunwind-git

.include "../../wip/llvm-git/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
