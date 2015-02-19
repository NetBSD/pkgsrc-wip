# $NetBSD: buildlink3.mk,v 1.1 2015/02/19 21:21:12 jihbed Exp $

BUILDLINK_TREE+=	cinnamon-menus

.if !defined(CINNAMON_MENUS_BUILDLINK3_MK)
CINNAMON_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-menus+=	cinnamon-menus>=2.2.0
BUILDLINK_PKGSRCDIR.cinnamon-menus?=	../../wip/cinnamon-menus

.include "../../devel/glib2/buildlink3.mk"
.endif	# CINNAMON_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-menus
