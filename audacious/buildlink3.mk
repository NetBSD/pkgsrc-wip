# $NetBSD: buildlink3.mk,v 1.15 2012/05/19 05:49:15 lokivit Exp $

BUILDLINK_TREE+=        audacious

.if !defined(AUDACIOUS_BUILDLINK3_MK)
AUDACIOUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audacious+=       audacious>=3.2.2
BUILDLINK_ABI_DEPENDS.audacious?=       audacious>=3.2.2
BUILDLINK_PKGSRCDIR.audacious?= ../../wip/audacious
BUILDLINK_DEPMETHOD.audacious?= build

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../devel/libmcs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.endif # AUDACIOUS_BUILDLINK3_MK

BUILDLINK_TREE+=        -audacious
