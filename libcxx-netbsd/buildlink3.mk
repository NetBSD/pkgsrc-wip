# $NetBSD$

BUILDLINK_TREE+=	libcxx

.if !defined(LIBCXX_BUILDLINK3_MK)
LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxx+=	libcxx>=3.9.0nb20151127
BUILDLINK_PKGSRCDIR.libcxx?=	../../wip/libcxx-git

.include "../../wip/llvm-git/buildlink3.mk"
.endif	# LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxx
