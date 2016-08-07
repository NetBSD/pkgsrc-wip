# $NetBSD: buildlink3.mk,v 1.1 2013/11/15 12:14:47 rhialto Exp $

BUILDLINK_TREE+=	py-pyside-shiboken

.if !defined(PY_PYSIDE_SHIBOKEN_BUILDLINK3_MK)
PY_PYSIDE_SHIBOKEN_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pyside-shiboken+=	${PYPKGPREFIX}-pyside-shiboken>=1.2.1
BUILDLINK_ABI_DEPENDS.py-pyside-shiboken+=	${PYPKGPREFIX}-pyside-shiboken>=1.2.1
BUILDLINK_PKGSRCDIR.py-pyside-shiboken?=	../../wip/py-pyside-shiboken
.endif # PY_PYSIDE_SHIBOKEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyside-shiboken
