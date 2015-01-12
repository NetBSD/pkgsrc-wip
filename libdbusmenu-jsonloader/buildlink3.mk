# $NetBSD: buildlink3.mk,v 1.1 2015/01/12 11:32:43 obache Exp $

BUILDLINK_TREE+=	libdbusmenu-jsonloader

.if !defined(LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK)
LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-jsonloader+=	libdbusmenu-jsonloader>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-jsonloader?=	../../wip/libdbusmenu-jsonloader

.include "../../wip/libdbusmenu-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-jsonloader
