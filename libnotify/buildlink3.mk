# $NetBSD: buildlink3.mk,v 1.1 2013/03/09 22:24:53 othyro Exp $

BUILDLINK_TREE+=	libnotify

.if !defined(LIBNOTIFY_BUILDLINK3_MK)
LIBNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.6.1
BUILDLINK_ABI_DEPENDS.libnotify+=	libnotify>=0.6.1
BUILDLINK_PKGSRCDIR.libnotify?=	../../sysutils/libnotify

.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify
