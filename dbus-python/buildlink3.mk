# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/11/30 13:44:46 rxg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DBUS_PYTHON_BUILDLINK3_MK:=	${DBUS_PYTHON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dbus-python
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndbus-python}
BUILDLINK_PACKAGES+=	dbus-python

.if !empty(DBUS_PYTHON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dbus-python+=	dbus-python>=0.23.4
BUILDLINK_PKGSRCDIR.dbus-python?=	../../sysutils/dbus-python
.endif	# DBUS_PYTHON_BUILDLINK3_MK

.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
