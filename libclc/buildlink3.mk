# $NetBSD: $

BUILDLINK_TREE+=	libclc

.if !defined(LIBCLC_BUILDLINK3_MK)
LIBCLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclc+=	libclc>=18.0.0
BUILDLINK_PKGSRCDIR.libclc?=	../../wip/libclc

.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.endif	# LIBCLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclc
