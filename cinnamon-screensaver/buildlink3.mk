# $NetBSD$
BUILDLINK_TREE+=	cinnamon-screensaver

.if !defined(CINNAMON_SCREENSAVER_BUILDLINK3_MK)
CINNAMON_SCREENSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-screensaver+=	cinnamon-screensaver>=4.6.0
BUILDLINK_PKGSRCDIR.cinnamon-screensaver?=	../../wip/cinnamon-screensaver

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../wip/cinnamon-desktop/buildlink3.mk"
.include "../../wip/xapps/buildlink3.mk"
.endif	# CINNAMON_SCREENSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-screensaver
