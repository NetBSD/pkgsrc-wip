# $NetBSD: buildlink3.mk,v 1.2 2006/01/17 09:13:38 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DBUS_PYTHON_BUILDLINK3_MK:=	${DBUS_PYTHON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dbus-python
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndbus-python}
BUILDLINK_PACKAGES+=	dbus-python

.if !empty(DBUS_PYTHON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dbus-python+=	dbus-python>=0.23.4
BUILDLINK_PKGSRCDIR.dbus-python?=	../../wip/dbus-python
.endif	# DBUS_PYTHON_BUILDLINK3_MK

.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
