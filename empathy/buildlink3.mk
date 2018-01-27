# $NetBSD: buildlink3.mk,v 1.38 2015/04/25 14:20:27 tnn Exp $

BUILDLINK_TREE+=	empathy

.if !defined(EMPATHY_BUILDLINK3_MK)
EMPATHY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.empathy+=	empathy>=3.12.10
BUILDLINK_PKGSRCDIR.empathy?=	../../wip/empathy

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/evolution-data-server/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # EMPATHY_BUILDLINK3_MK

BUILDLINK_TREE+=	-empathy
