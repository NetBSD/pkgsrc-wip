# $NetBSD: buildlink3.mk,v 1.1 2013/03/27 15:04:27 othyro Exp $

BUILDLINK_TREE+=	py-notify

.if !defined(PY_NOTIFY_BUILDLINK3_MK)
PY_NOTIFY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-notify+=	${PYPKGPREFIX}-notify>=0.2.0
BUILDLINK_ABI_DEPENDS.py-notify+=	${PYPKGPREFIX}-notify>=0.2.0
BUILDLINK_PKGSRCDIR.py-notify?=		../../sysutils/py-notify

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2
.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_NOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-notify
