# $NetBSD$

BUILDLINK_TREE+=	libsearpc

.if !defined(LIBSEARPC_BUILDLINK3_MK)
LIBSEARPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsearpc+=	libsearpc>=3.0
BUILDLINK_PKGSRCDIR.libsearpc?=		../../wip/libsearpc
.endif	# LIBSEARPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsearpc
