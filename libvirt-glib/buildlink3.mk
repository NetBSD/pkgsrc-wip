# $NetBSD$

BUILDLINK_TREE+=	libvirt-glib

.if !defined(LIBVIRT_GLIB_BUILDLINK3_MK)
LIBVIRT_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvirt-glib+=	libvirt-glib>=2.0.0
BUILDLINK_PKGSRCDIR.libvirt-glib?=	../../wip/libvirt-glib

.include "../../wip/libvirt/buildlink3.mk"
.endif	# LIBVIRT_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvirt-glib
