# $NetBSD$

BUILDLINK_TREE+=	cinnamon-menus

.if !defined(CINNAMON_MENUS_BUILDLINK3_MK)
CINNAMON_MENUS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cinnamon-menus?=	build

BUILDLINK_API_DEPENDS.cinnamon-menus+=	cinnamon-menus>=5.6.0
BUILDLINK_PKGSRCDIR.cinnamon-menus?=	../../wip/cinnamon-menus


.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# CINNAMON_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-menus
