# $NetBSD$

BUILDLINK_TREE+=	libdivecomputer

.if !defined(LIBDIVECOMPUTER_BUILDLINK3_MK)
LIBDIVECOMPUTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdivecomputer+=	libdivecomputer>=0.6.0
BUILDLINK_ABI_DEPENDS.libdivecomputer+=	libdivecomputer>=0.6.0
BUILDLINK_PKGSRCDIR.libdivecomputer?=	../../wip/libdivecomputer

.endif # LIBDIVECOMPUTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdivecomputer
