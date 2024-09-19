# $NetBSD$

BUILDLINK_TREE+=	libgusb

.if !defined(LIBGUSB_BUILDLINK3_MK)
LIBGUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgusb+=	libgusb>=0.3.5
BUILDLINK_PKGSRCDIR.libgusb?=	../../wip/libgusb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.endif	# LIBGUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgusb
