# $NetBSD$

BUILDLINK_TREE+=	libclc

.if !defined(LIBCLC_BUILDLINK3_MK)
LIBCLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclc+=	libclc>=23.1.0
BUILDLINK_PKGSRCDIR.libclc?=	../../wip/libclc

.include "../../wip/llvm/buildlink3.mk"
.include "../../wip/spirv-llvm-translator/buildlink3.mk"
.endif	# LIBCLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclc
