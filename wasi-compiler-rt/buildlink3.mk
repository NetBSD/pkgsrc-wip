# $NetBSD: buildlink3.mk,v 1.6 2023/01/26 01:03:01 gutteridge Exp $

BUILDLINK_TREE+=	wasi-compiler-rt

BUILDLINK_DEPMETHOD.wasi-compiler-rt?=	build

.if !defined(WASI_COMPILER_RT_BUILDLINK3_MK)
WASI_COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-compiler-rt+=	wasi-compiler-rt>=21.1.0
BUILDLINK_PKGSRCDIR.wasi-compiler-rt?=		../../wip/wasi-compiler-rt

.endif	# WASI_COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-compiler-rt
