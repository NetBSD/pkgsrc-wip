# $NetBSD: buildlink3.mk,v 1.4 2015/04/10 12:26:52 krytarowski Exp $

BUILDLINK_TREE+=	system-tools-backends

.if !defined(SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK)
SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.system-tools-backends+=	system-tools-backends>=2.10.0
BUILDLINK_PKGSRCDIR.system-tools-backends?=	../../wip/system-tools-backends

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-system-tools-backends
