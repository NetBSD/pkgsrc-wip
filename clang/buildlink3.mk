# $NetBSD: buildlink3.mk,v 1.1 2010/05/04 15:33:16 drochner Exp $

BUILDLINK_TREE+=	llvm

.if !defined(LLVM_BUILDLINK3_MK)
LLVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm+=	llvm>=2.1
BUILDLINK_PKGSRCDIR.llvm?=	../../wip/llvm
.endif # LLVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-llvm
