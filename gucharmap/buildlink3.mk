# $NetBSD$

BUILDLINK_TREE+=	gucharmap

.if !defined(GUCHARMAP_BUILDLINK3_MK)
GUCHARMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gucharmap+=	gucharmap>=10.0.0
BUILDLINK_PKGSRCDIR.gucharmap?=	../../wip/gucharmap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# GUCHARMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gucharmap
