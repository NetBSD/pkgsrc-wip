# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/07 16:33:13 jihbed Exp $

BUILDLINK_TREE+=	notify-sharp

.if !defined(NOTIFY_SHARP_BUILDLINK3_MK)
NOTIFY_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.notify-sharp+=	notify-sharp>=0.4.0
BUILDLINK_PKGSRCDIR.notify-sharp?=	../../wip/notify-sharp


.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"

.endif	# NOTIFY_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-notify-sharp
