# $NetBSD: buildlink3.mk,v 1.1 2015/01/01 08:17:39 obache Exp $
#

BUILDLINK_TREE+=	mate-menus

.if !defined(MATE_MENUS_BUILDLINK3_MK)
MATE_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-menus+=	mate-menus>=1.8.0
BUILDLINK_PKGSRCDIR.mate-menus?=	../../wip/mate-menus

.include "../../devel/glib2/buildlink3.mk"
.endif	# MATE_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-menus
