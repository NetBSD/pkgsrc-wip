# $NetBSD$

BUILDLINK_TREE+=	mlir

.if !defined(MLIR_BUILDLINK3_MK)
MLIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlir+=	mlir>=20.1.0
BUILDLINK_PKGSRCDIR.mlir?=	../../wip/mlir

BUILDLINK_FILES.mlir+=		bin/mlir-tblgen

.include "../../lang/llvm/buildlink3.mk"
.endif	# MLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlir
