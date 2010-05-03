# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/03 14:57:45 jihbed Exp $

BUILDLINK_TREE+=	libslab

.if !defined(LIBSLAB_BUILDLINK3_MK)
LIBSLAB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslab+=	libslab>=2.30.0
BUILDLINK_PKGSRCDIR.libslab?=	../../wip/libslab

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBSLAB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslab
