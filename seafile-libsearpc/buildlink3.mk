# $NetBSD$

BUILDLINK_TREE+=	seafile-libsearpc
BUILDLINK_TREE+=	libsearpc
BUILDLINK_TREE+=	searpc

.if !defined(SEAFILE_LIBSEARPC_BUILDLINK3_MK)
SEAFILE_LIBSEARPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seafile-libsearpc+=	seafile-libsearpc>=3.00
BUILDLINK_PKGSRCDIR.seafile-libsearpc?=	../../wip/seafile-libsearpc
.endif	# SEAFILE_LIBSEARPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-seafile-libsearpc
BUILDLINK_TREE+=	-libsearpc
BUILDLINK_TREE+=	-searpc
