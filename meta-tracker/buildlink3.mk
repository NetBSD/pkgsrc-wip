# $NetBSD: buildlink3.mk,v 1.1 2010/05/01 22:36:53 thomasklausner Exp $

BUILDLINK_TREE+=	meta-tracker

.if !defined(META_TRACKER_BUILDLINK3_MK)
META_TRACKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meta-tracker+=	meta-tracker>=0.6.96
BUILDLINK_PKGSRCDIR.meta-tracker?=	../../wip/meta-tracker

.include "../../databases/qdbm/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# META_TRACKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-meta-tracker
