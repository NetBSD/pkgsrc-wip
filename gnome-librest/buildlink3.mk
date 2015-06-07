# $NetBSD: buildlink3.mk,v 1.2 2015/06/07 14:24:48 yrmt Exp $

BUILDLINK_TREE+=	gnome-librest

.if !defined(GNOME_LIBREST_BUILDLINK3_MK)
GNOME_LIBREST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-librest+=	gnome-librest>=0.7.10
BUILDLINK_PKGSRCDIR.gnome-librest?=	../../wip/gnome-librest

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GNOME_LIBREST_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-librest
