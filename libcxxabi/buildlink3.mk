# $NetBSD: buildlink3.mk,v 1.6 2022/08/12 08:41:58 pin Exp $

BUILDLINK_TREE+=	libcxxabi

.if !defined(LIBCXXABI_BUILDLINK3_MK)
LIBCXXABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxxabi+=	libcxxabi>=20.1.0
BUILDLINK_PKGSRCDIR.libcxxabi?=		../../wip/libcxxabi

.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/libunwind/buildlink3.mk"
.endif	# LIBCXXABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxxabi
