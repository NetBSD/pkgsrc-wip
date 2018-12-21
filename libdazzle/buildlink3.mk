# $NetBSD$

BUILDLINK_TREE+=	libdazzle

.if !defined(LIBDAZZLE_BUILDLINK3_MK)
LIBDAZZLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdazzle+=	libdazzle>=3.30.2
BUILDLINK_PKGSRCDIR.libdazzle?=		../../wip/libdazzle

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBDAZZLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdazzle
