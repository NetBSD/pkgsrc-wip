# $NetBSD: buildlink3.mk,v 1.1 2015/01/01 08:01:44 obache Exp $
#

BUILDLINK_TREE+=	caja

.if !defined(CAJA_BUILDLINK3_MK)
CAJA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.caja+=	caja>=1.8.2
BUILDLINK_PKGSRCDIR.caja?=	../../wip/caja

#.include "../../mate/mate-desktop/buildlink3.mk"
#.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
#.include "../../devel/pangox-compat/buildlink3.mk"
#.include "../../graphics/libexif/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libunique/buildlink3.mk"
.endif	# CAJA_BUILDLINK3_MK

BUILDLINK_TREE+=	-caja
