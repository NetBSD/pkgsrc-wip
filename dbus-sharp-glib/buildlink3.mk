# $NetBSD: buildlink3.mk,v 1.1 2012/09/10 23:52:19 othyro Exp $

BUILDLINK_TREE+=	dbus-sharp-glib

.if !defined(DBUS_SHARP_GLIB_BUILDLINK3_MK)
DBUS_SHARP_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus-sharp-glib+=	dbus-sharp-glib>=0.5.1
BUILDLINK_PKGSRCDIR.dbus-sharp-glib?=	../../wip/dbus-sharp-glib

#.include "../../wip/dbus-sharp/buildlink3.mk"
.endif	# DBUS_SHARP_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-sharp-glib
