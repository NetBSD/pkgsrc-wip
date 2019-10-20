# $NetBSD$

BUILDLINK_TREE+=	libosinfo

.if !defined(LIBOSINFO_BUILDLINK3_MK)
LIBOSINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosinfo+=	libosinfo>=1.2.0
BUILDLINK_PKGSRCDIR.libosinfo?=		../../wip/libosinfo

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.endif	# LIBOSINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosinfo
