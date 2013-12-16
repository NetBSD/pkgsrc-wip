# $NetBSD: buildlink3.mk,v 1.1 2013/12/16 08:15:46 nsloss Exp $

BUILDLINK_TREE+=	llvm-rtlib

.if !defined(LLVM_RTLIB_BUILDLINK3_MK)
LLVM_RTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.llvm-rtlib+=	llvm-rtlib>=2.8
BUILDLINK_PKGSRCDIR.llvm-rtlib?=	../../wip/llvm-rtlib
.endif

BUILDLINK_TREE+=	-llvm-rtlib
