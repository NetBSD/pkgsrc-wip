# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/05 18:18:42 jihbed Exp $

BUILDLINK_TREE+=	gnome-librest

.if !defined(GNOME_LIBREST_BUILDLINK3_MK)
GNOME_LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-librest+=	gnome-librest>=0.7.10
BUILDLINK_PKGSRCDIR.gnome-librest?=	../../wip/gnome-librest

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GNOME_LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-librest
