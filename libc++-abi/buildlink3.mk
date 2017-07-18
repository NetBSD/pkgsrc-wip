# $NetBSD$

BUILDLINK_TREE+=	libc++-abi

.if !defined(LIBC++_ABI_BUILDLINK3_MK)
LIBC++_ABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libc++-abi+=	libc++-abi>=4.0.0
BUILDLINK_PKGSRCDIR.libc++-abi?=	../../lang/libc++-abi

.endif	# LIBC++_ABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libc++-abi
