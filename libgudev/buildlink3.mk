# $NetBSD$

BUILDLINK_TREE+=	libgudev

.if !defined(LIBGUDEV_BUILDLINK3_MK)
LIBGUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgudev+=	libgudev>=237
BUILDLINK_PKGSRCDIR.libgudev?=		../../wip/libgudev

.include "../../wip/libudev/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# LIBGUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgudev
