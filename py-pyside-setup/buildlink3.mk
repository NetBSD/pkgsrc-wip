# $NetBSD: $

BUILDLINK_TREE+=	py-pyside-setup

.if !defined(PY_PYSIDE_SETUP_BUILDLINK3_MK)
PY_PYSIDE_SETUP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pyside-setup+=	${PYPKGPREFIX}-pyside-setup>=5.0.0
BUILDLINK_ABI_DEPENDS.py-pyside-setup+=	${PYPKGPREFIX}-pyside-setup>=5.0.0
BUILDLINK_PKGSRCDIR.py-pyside-setup?=	../../wip/py-pyside-setup
.endif # PY_PYSIDE_SETUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyside-setup
