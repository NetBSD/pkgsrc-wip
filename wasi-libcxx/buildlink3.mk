# $NetBSD$

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=19.1.0
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../wip/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
